#include "ConvertAll.h"
#include <wx/wx.h>
#include <iostream>

ConvertAll::ConvertAll(cs::Flags flags) : m_flags(flags)
{
}

bool ConvertAll::convert_to(const char *from, const char *to, cs::PictureFormat format)
{
    try {
        m_image.load(from);
        if (format & cs::FORMAT_PNG)  {m_image.save_png(to); return true;}
        if (format & cs::FORMAT_JPG)  {m_image.save_jpeg(to); return true;}
        
        if (format & cs::FORMAT_WBP)  {m_image.save_webp(to); return true;}
        if (format & cs::FORMAT_ASCII){m_image.save_ascii(to); return true;}
        if (format & cs::FORMAT_BMP)  {m_image.save_bmp(to); return true;}
        if(format & cs::FORMAT_SVM)   {m_image.save_cpp(to); return true;}
    } catch (img::CImgIOException exc){
        wxLogError(wxString::Format("A Error occured. DATA: '%s'", exc.what()));
    } catch (img::CImgArgumentException exc){
        wxLogError(wxString::Format("A Error occured. DATA: '%s'", exc.what()));
    } catch (img::CImgWarningException exc){
        wxLogWarning(wxString::Format("A Error occured. DATA: '%s'", exc.what()));
    }

    return false;
}
