#pragma once
#include <wx/log.h>
#include <wx/artprov.h>
class CLog :
    public wxLog
{
public:
    CLog(wxWindow* parent);
private:
    wxWindow* m_parent;
protected:
    void DoLogRecord(wxLogLevel level,
        const wxString& msg,
        const wxLogRecordInfo& info) override;
};

