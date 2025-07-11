#include <main.h>
#include <wx/wx.h>
#include <wx/image.h>
#include <CLog.h>
#include <ConvertAll.h>
#include <filesystem>
#include <CImg.h>
#include <wx/mstream.h>
typedef unsigned char uint8;
#include <icon.h>
bool App::OnInit(){
    wxInitAllImageHandlers();
    WindowFrame* win = new WindowFrame("Picture converter", {700,700});
    wxMemoryInputStream stream(icon3_png, sizeof(icon3_png));
    wxImage image(stream, wxBITMAP_TYPE_PNG);

    if (image.IsOk()) {
        wxIcon icon;
        icon.CopyFromBitmap(wxBitmap(image));
        win->SetIcon(icon);
    }

    win->Show();
    
    return true;
}
void App::OnFatalException(){
    wxLogError("A Fatal error has occured. Please contact the developers for more info. Closing application.");
    ExitMainLoop();
}
wxIMPLEMENT_APP(App);