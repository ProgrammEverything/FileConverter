#pragma once
#include <wx/wx.h>
#include <wx/clipbrd.h>
#include <wx/artprov.h>
class InfoBox :
    public wxDialog
{
public:
    InfoBox(wxWindow* parent, wxString content, wxString title,wxString metadata,const wxBitmap ic, bool disabled=true, long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);

    void CloseButtonHandle(wxCommandEvent& evt);
    void CopyButtonHandle(wxCommandEvent& evt);
    void CopyMetaButtonHandle(wxCommandEvent& evt);
    bool CopyToClipboard(const wxString& text);
private:
    wxArtProvider* m_prov;
    wxString m_content;
    wxString m_metadata;
    wxTextCtrl* m_txt;
    wxStaticText* m_title;
    wxStaticBitmap* m_bit;
    wxButton* m_btn;
    wxButton* m_btn_cpy;
    wxButton* m_btn_meta;
};

