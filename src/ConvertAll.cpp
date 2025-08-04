#include "ConvertAll.h"
#include <wx/wx.h>
#include <iostream>

ConvertAll::ConvertAll(cs::Flags flags) : m_flags(flags)
{
}



bool ConvertAll::convert_to(cs::PictureString str, cs::TypeFormat format)
{
    try {
        m_image.load(str.from);
        if (format & cs::FORMAT_PNG)  {m_image.save_png(str.to);}
        else if (format & cs::FORMAT_JPG)  {m_image.save_jpeg(str.to);}
        else if (format & cs::FORMAT_WBP)  {m_image.save_webp(str.to);}
        else if (format & cs::FORMAT_ASCII){m_image.save_ascii(str.to);}
        else if (format & cs::FORMAT_BMP)  {m_image.save_bmp(str.to);}
        else if(format & cs::FORMAT_SVM)   {m_image.save_cpp(str.to);}
        else return false;
    } catch (img::CImgException exc){
        wxLogError(wxString::Format("An Error occured. DATA: '%s'", exc.what()));
        return false;
    }

    return true;
}

bool ConvertAll::convert_to(cs::MovieString str, cs::TypeFormat format)
{
    wxString cmd = wxString::Format("ffmpeg -y -i \"%s\" -c copy \"%s\"", str.from, str.to + cs::GetPictureFormat(format));
    int ret = std::system(cmd.c_str());
    return ret == 0;
}
