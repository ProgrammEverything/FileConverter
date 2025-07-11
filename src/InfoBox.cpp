#include "InfoBox.h"
// TODO: Move all definitions of member vars to the constructor
InfoBox::InfoBox(wxWindow* parent, wxString content,wxString title, wxString metadata,const wxBitmap ic, bool disabled, long style) :
	wxDialog(parent, wxID_ANY, "InformationBox",wxDefaultPosition,wxDefaultSize, style), m_metadata(metadata), m_content(content)
{
	m_prov = new wxArtProvider();
	m_btn_cpy = new wxButton(this, wxID_ANY, "Copy");
	m_btn_meta = new wxButton(this, wxID_ANY, "Copy metadata");
	m_bit = new wxStaticBitmap(this, wxID_ANY, ic);
	m_title = new wxStaticText(this, wxID_ANY, title);
	m_btn = new wxButton(this, wxID_OK, "Ok!");
	m_txt = new wxTextCtrl(this, wxID_ANY, content, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | (disabled ? wxTE_READONLY : 0));
	
	m_btn->Bind(wxEVT_BUTTON, &InfoBox::CloseButtonHandle, this);
	if (m_metadata != wxEmptyString && disabled) {
		m_btn_meta->Bind(wxEVT_BUTTON, &InfoBox::CopyMetaButtonHandle, this);
	}
	else {
		m_btn_meta->Disable();
	}
	if (m_content != wxEmptyString && disabled) {
		m_btn_cpy->Bind(wxEVT_BUTTON, &InfoBox::CopyButtonHandle, this);
	}
	else {
		m_btn_cpy->Disable();
	}
	
	/////////////////////

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* sizer2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* sizer3 = new wxBoxSizer(wxHORIZONTAL);
	sizer->Add(sizer2, 0, wxEXPAND);
	
	sizer2->Add(m_bit, 0, wxALIGN_CENTER | wxUP | wxDOWN | wxLEFT, 10);
	sizer2->Add(m_title, 0, wxALIGN_CENTER | wxLEFT, 5);
	sizer2->AddStretchSpacer(1);
	sizer2->Add(m_btn, 0, wxALIGN_CENTER);
	sizer->Add(m_txt, 1, wxEXPAND | wxALL, 10);
	sizer3->Add(m_btn_cpy);
	sizer3->Add(m_btn_meta);
	sizer->Add(sizer3, 0, wxEXPAND);

	
	//////////////////////
	SetSizer(sizer);

	sizer->SetSizeHints(this);
	SetSize(wxSize(700,700));
}

void InfoBox::CloseButtonHandle(wxCommandEvent& evt)
{
	EndModal(evt.GetId());
}

void InfoBox::CopyButtonHandle(wxCommandEvent& evt)
{
	if (CopyToClipboard(m_content)) {
		wxMessageBox("Copied Sucessfully", "Copied", wxOK, this);
	} else {
		wxMessageBox("Could not copy", "Could not copy the string. Contact the developers for more info.", wxOK, this);
	}
}

void InfoBox::CopyMetaButtonHandle(wxCommandEvent& evt)
{
	if (CopyToClipboard(m_metadata)) {
		wxMessageBox("Copied Sucessfully", "Copied", wxOK, this);
	}
	else {
		wxMessageBox("Could not copy", "Could not copy the string. Contact the developers for more info.", wxOK, this);
	}
}

bool InfoBox::CopyToClipboard(const wxString& text)
{
	if (wxTheClipboard->Open()) {
		wxTheClipboard->Clear();
		wxTextDataObject* dataObject = new wxTextDataObject(text);
		if (!wxTheClipboard->SetData(dataObject)) {
			wxTheClipboard->Close();
			return false;
		}
		wxTheClipboard->Flush();
		wxTheClipboard->Close();
		return true;
	}
	else {
		wxTheClipboard->Close();
		return false;
	}
}