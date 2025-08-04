#include <WindowFrame.h>
#include "InfoBox.h"
#include <wx/string.h>
#include <wx/splitter.h>
#include <CLog.h>
#include <ConvertAll.h>
#include <wx/filename.h>
#include <constants.h>
#include <math.h>
enum bindingId : int{
    ID_EXPORT = 1,
    ID_CANCEL ,
    ID_IMPORT ,
    ID_TYPE,
    ID_SAVE_EXPORT,
    ID_SELECT_ALL
};
WindowFrame::WindowFrame(wxString title, wxSize size, long style) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, size, style)
{
    
    ///////////////////////////////////////
    if (!SetupWidgets()) {wxLogFatalError("SetupWidgets failed. Closing program.");}
    if (!SetupSizers())  {wxLogFatalError("SetupSizers failed. Closing program.");}
    if (!SetupBinding()) {wxLogFatalError("SetupBinding failed. Closing program.");}
    wxLog::SetActiveTarget(new CLog(this));
}

bool WindowFrame::SetupWidgets()
{
    try{
        m_splitter = new wxSplitterWindow(this);
        
        m_panel1 = new wxPanel(m_splitter);
        m_panel2 = new wxPanel(m_splitter);
        m_splitter->SplitHorizontally(m_panel1, m_panel2, 0);  // Horizontal split
        m_toolbar = new wxToolBar(m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_TOP | wxTB_HORZ_TEXT );
        m_toolbar_choice = new wxChoice(m_toolbar, ID_TYPE, wxDefaultPosition, wxDefaultSize, (const wxString *) nullptr);
        m_toolbar_choice->Select(0); // Select the first item. By default it doesn't (Atleast in gtk)
        m_toolbar_cancel = m_toolbar->AddTool(ID_CANCEL, "Cancel", wxArtProvider::GetBitmap(wxART_DELETE), "Cancel the selections");
        m_toolbar_import = m_toolbar->AddTool(ID_IMPORT, "Import files", wxArtProvider::GetBitmap(wxART_FILE_OPEN), "Import file(s)");
        m_toolbar_export = m_toolbar->AddTool(ID_EXPORT, "Export", wxArtProvider::GetBitmap(wxART_FILE_SAVE), "Select files for export");
        m_toolbar_save_export = m_toolbar->AddTool(ID_SAVE_EXPORT, "Save to export list", wxArtProvider::GetBitmap(wxART_NORMAL_FILE), "Save to export list");
        m_toolbar_select_all  = m_toolbar->AddTool(ID_SELECT_ALL, "Select all items", wxArtProvider::GetBitmap(wxART_ADD_BOOKMARK), "Select/Deselect All items");
        m_toolbar->AddStretchableSpace();
        m_toolbar_type = m_toolbar->AddControl(m_toolbar_choice);
        m_panel1_listbox = new wxListBox(m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxArrayString{}, wxLB_MULTIPLE | wxLB_HSCROLL);
        m_panel2_listbox = new wxListBox(m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxArrayString{}, 0L, wxDefaultValidator, "Export list");
        m_panel2_listbox_title = new wxStaticText(m_panel2, wxID_ANY, "Files ready for export");
    // catch ALL exceptions
    } catch (...){
        // Terminate the program
        return false;
    }
    return true;
}

bool WindowFrame::SetupSizers()
{
    try{
        ///////////////////// SETUP SIZERS
        wxBoxSizer* sizer_main = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* sizer_panel1 = new wxBoxSizer(wxVERTICAL);
        
        wxBoxSizer* sizer_panel2 = new wxBoxSizer(wxVERTICAL);    
        ///////////////////// SIZER CONFIGURATIONS
        sizer_panel1->Add(m_toolbar, 0, wxEXPAND);
        sizer_panel1->Add(m_panel1_listbox, 1, wxEXPAND | wxTOP, 2);
        ///////////////////// SIZER CONFIGURATIONS
        sizer_panel2->Add(m_panel2_listbox_title, 0, wxEXPAND | wxLEFT, 20);
        sizer_panel2->Add(m_panel2_listbox, 1, wxEXPAND);
        
        ///////////////////// TOOL BAR CONFIGURATION
        m_toolbar->SetBackgroundColour(wxColor{64, 61, 58});
        ///////////////////// SIZER PANEL CONFIGURATIONS
        m_panel1->SetSizer(sizer_panel1);
        m_panel2->SetSizer(sizer_panel2);
        
        ///////////////////// LAYOUT CONFIGURATIONS
        sizer_main->Add(m_splitter, 1, wxEXPAND);
        m_panel1->SetMinSize(m_panel1->GetBestSize());
        m_panel2->SetMinSize(m_panel2->GetBestSize());
        m_splitter->SetMinimumPaneSize( std::max(m_panel1->GetBestSize().y, m_panel2->GetBestSize().y) );
        this->SetSizer(sizer_main);
        wxSize size = this->GetBestSize();
        size.x + 50; // To fix a bug where the comboBox dissappears when resized (Not using this->SetSizerAndFit)
        size.y + 50;
        this->SetMinSize(size);
    // Catch ALL exceptions
    } catch (...){
        // Terminate the program
        return false;
    }
    return true;
}

bool WindowFrame::SetupBinding()
{
    try {
        // Bind every button in the toolbar
        m_toolbar->Bind(wxEVT_COMMAND_TOOL_CLICKED, &WindowFrame::TOOLBAR_CANCEL, this, ID_CANCEL);
        m_toolbar->Bind(wxEVT_COMMAND_TOOL_CLICKED, &WindowFrame::TOOLBAR_EXPORT, this, ID_EXPORT);
        m_toolbar->Bind(wxEVT_COMMAND_TOOL_CLICKED, &WindowFrame::TOOLBAR_IMPORT_FILES, this, ID_IMPORT);
        m_toolbar->Bind(wxEVT_COMMAND_TOOL_CLICKED, &WindowFrame::TOOLBAR_SAVE_EXPORT, this, ID_SAVE_EXPORT);
        m_toolbar->Bind(wxEVT_COMMAND_TOOL_CLICKED, &WindowFrame::TOOLBAR_SELECT_ALL, this, ID_SELECT_ALL);

    // Any kind of freaky error catched here
    } catch (...){
        // Return false. Terminate the program.
        return false;
    }
    return true;
}



void WindowFrame::TOOLBAR_CANCEL(wxCommandEvent &evt) // TODO: Change this disgusting If statement
{
    wxArrayInt array;
    if (m_panel1_listbox->HasFocus()){
        m_panel1_listbox->GetSelections(array);
        if (array.size() > 0) {
            // Delete in reverse order to avoid messing up indices
            for (int i = array.size() - 1; i >= 0; --i) {
                m_panel1_listbox->Delete(array[i]);
            }
        }
    } else if (m_panel2_listbox->HasFocus()){
        m_panel2_listbox->GetSelections(array);
        if (array.size() > 0) {
            // Delete in reverse order to avoid messing up indices
            for (int i = array.size() - 1; i >= 0; --i) {
                m_panel2_listbox->Delete(array[i]);
            }
        }
    }
}


void WindowFrame::TOOLBAR_IMPORT_FILES(wxCommandEvent &evt)
{
    wxFileDialog* file_dialog = new wxFileDialog(this, "Select file(s) for import", wxEmptyString, wxEmptyString, 
        "Image files (*.png, *.bmp, *.asc, *.svm, *.jpg, *.jpeg)|*.png;*.bmp;*.asc;*.svm;*.jpg;*.jpeg|"
        "All files (*.*)|*.*",
        wxFD_MULTIPLE | wxFD_FILE_MUST_EXIST
    );
    if (file_dialog->ShowModal() != wxID_CANCEL){
        
        wxArrayString values;
        file_dialog->GetPaths(values);
        for (const wxString ref : values){
            if (cs::GetFormatByExtImage(ref) != cs::EMPTY){
                isMovie=true;
            } else
            {
                isMovie=false;
            }
        }
        m_panel1_listbox->Append(values);
    }
}

void WindowFrame::TOOLBAR_SAVE_EXPORT(wxCommandEvent &evt)
{
    //Copy all the values from the first panel's listbox to the other
    wxArrayString values;
    for (unsigned int x=0; x < m_panel1_listbox->GetCount(); ++x){
        m_panel2_listbox->Append(m_panel1_listbox->GetString(x));
    }
    m_panel1_listbox->Clear();
}

void WindowFrame::TOOLBAR_EXPORT(wxCommandEvent &evt)
{
    if (m_panel2_listbox->GetCount() == 0){
        wxLogError("No items are selected");
        return;
    }
    int convert_value = pow(2, m_toolbar_choice->GetSelection()); // PictureFormat is 2**n 
    /*
    PictureFormat is a bitflag meaning each number is starting from 0 to the power of two
    0x01 = 1
    0x02 = 2
    0x04 = 4
    0x08 = 8
    0x10 = 16
    ...
    */
    cs::TypeFormat format = static_cast<cs::TypeFormat>(convert_value);
    wxString log; // Log!
    wxFileDialog* file = new wxFileDialog(this, "Where to save the file(s)?", wxEmptyString, "Untitled", wxFileSelectorDefaultWildcardStr, wxFD_SAVE);
    if (file->ShowModal() != wxID_CANCEL){
        for (unsigned int x=0; x < m_panel2_listbox->GetCount() ; ++x){
            wxString path = ModifyPath(file->GetPath(), isMovie? cs::GetMovieFormat(format) : cs::GetPictureFormat(format), wxString::Format("%u", x));
            bool result;
            if (isMovie)
                result = converter.convert_to(cs::MovieString{m_panel2_listbox->GetString(x), path} , format);
            else
                result = converter.convert_to(cs::PictureString{m_panel2_listbox->GetString(x), path} , format);
            log += wxString::Format("DONE %u RESULT : %s FILEPATH : %s\n", x+1, result? "TRUE" : "FALSE", path); // Logging
        }
        wxLogInfo(wxString::Format("Execution data. Log:\n%s", log));
        m_panel2_listbox->Clear();
    }
}

void WindowFrame::TOOLBAR_SELECT_ALL(wxCommandEvent &evt) // TODO: Change this disgusting If statement. Works for now :>
{
    static bool was_selected = false;
    if (m_panel1_listbox->HasFocus()){
        int count = m_panel1_listbox->GetCount();
        for (unsigned int i = 0; i < count; ++i) {
            m_panel1_listbox->SetSelection(i, was_selected);
        }
        was_selected = !was_selected;
    } else if (m_panel2_listbox->HasFocus()){
        int count = m_panel1_listbox->GetCount();
        for (unsigned int i = 0; i < count; ++i) {
            m_panel1_listbox->SetSelection(i, was_selected);
        }
        was_selected = !was_selected;
    }
}

const wxString WindowFrame::ModifyPath(const wxString str, const wxString ext, const wxString add_name)
{
    wxFileName file(str);
    file.SetName(file.GetName() + add_name);
    return file.GetFullPath();
}

const wxString WindowFrame::GetExtentsion(const wxString str)
{
    wxFileName file(str);
    return file.GetExt();
}
