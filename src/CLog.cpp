#include <CLog.h>
#include <InfoBox.h>

CLog::CLog(wxWindow* parent)
{
	m_parent = parent;
}
void CLog::DoLogRecord(wxLogLevel level, const wxString& msg, const wxLogRecordInfo& info)
{
	wxBell();
	wxString metadata = wxString::Format("[%lu][%d][%s][%llu][%llu]", level, info.line, info.func, info.threadId, info.timestampMS);
	wxString m = wxString::Format("[%d][%s][%llu][%llu]\n%s", info.line, info.func, info.threadId, info.timestampMS, msg);
	if (level == 0) {
		InfoBox* bx = new InfoBox(m_parent, "[FAILURE]" + m, "A Failure occured", metadata, wxArtProvider::GetBitmap(wxART_ERROR));
		bx->ShowModal();
	}
	else if (level == 1) {
		InfoBox* bx = new InfoBox(m_parent, "[ERROR]" + m, "An Error occured",metadata, wxArtProvider::GetBitmap(wxART_ERROR));
		bx->ShowModal();
	}
	else if (level == 2) {
		InfoBox* bx = new InfoBox(m_parent, "[WARNING]" + m, "A Warning occured", metadata, wxArtProvider::GetBitmap(wxART_WARNING));
		bx->ShowModal();
	}
	else {
		InfoBox* bx = new InfoBox(m_parent, "[INFORMATION]" + m,metadata, "Information!", wxArtProvider::GetBitmap(wxART_INFORMATION));
		bx->ShowModal();
	}
}