#pragma once
#include <wx/wx.h>
#include <wx/artprov.h>
#include <wx/splitter.h>
#include <ConvertAll.h>
class WindowFrame : public wxFrame {
public:

    /// @brief The constructor of WindowFrame
    /// @param title The title of the program
    /// @param size The size of the program
    /// @param style The style flags (known as BITFLAGS)
    WindowFrame(wxString title, wxSize size, long style = wxDEFAULT_FRAME_STYLE);
public:
    /// @brief Sets up widgets
    /// @return Success value
    bool SetupWidgets();
    /// @brief Sets up sizers
    /// @return Sucess value
    bool SetupSizers();
    /// @brief Sets up Binding
    /// @return Sucess value
    bool SetupBinding();
    
public:
    void TOOLBAR_CANCEL(wxCommandEvent& evt);
    void TOOLBAR_IMPORT_FILES(wxCommandEvent& evt);
    void TOOLBAR_SAVE_EXPORT(wxCommandEvent& evt);
    void TOOLBAR_EXPORT(wxCommandEvent& evt);
    void TOOLBAR_SELECT_ALL(wxCommandEvent& evt);
    // Some helper functions
public:
    const wxString ModifyPath(const wxString str, const wxString ext, const wxString add_name);
private:
    ConvertAll converter;
    ///////////////////
    wxPanel* m_panel1;
    wxPanel* m_panel2;
    ///////////////////
    wxListBox* m_panel1_listbox;
    wxStaticText* m_panel2_listbox_title;
    wxListBox* m_panel2_listbox;
    ///////////////////
    wxButton* m_export_files;
    wxToolBar* m_toolbar;
    wxToolBarToolBase* m_toolbar_export;
    wxToolBarToolBase* m_toolbar_cancel;
    wxToolBarToolBase* m_toolbar_import;
    wxToolBarToolBase* m_toolbar_type;
    wxToolBarToolBase* m_toolbar_save_export;
    wxToolBarToolBase* m_toolbar_select_all;
    wxChoice* m_toolbar_choice;
    wxSplitterWindow* m_splitter;
    bool isMovie=false;
};