#pragma once
#include <wx/wx.h>
#include "constants.h"
#include "CImg.h"
namespace img = cimg_library;
class ConvertAll{
public:
    ConvertAll() = default;
    ConvertAll(cs::Flags flags);

    bool convert_to(cs::PictureString str, cs::TypeFormat format);
    bool convert_to(cs::MovieString  str, cs::TypeFormat format);

private:
    cs::Flags m_flags = (cs::Flags)0;
    img::CImg<unsigned char> m_image;
};