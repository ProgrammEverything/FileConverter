#pragma once
#include <string_view>
#include <array>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <wx/string.h>
namespace cs{
    inline const wxArrayString picture_formats =  {
        "PNG Format",
        "JPG Format",
        "Webp Format",
        "Ascii Format",
        "Bitmap Format",
        "SVM(CPP) Format",
    };
    enum PictureFormat : int {
        FORMAT_PNG = 0x01,
        FORMAT_JPG = 0x02,
        FORMAT_WBP = 0x04,
        FORMAT_ASCII = 0x08,
        FORMAT_BMP = 0x10,
        FORMAT_SVM = 0x20,
    };
    enum Flags : unsigned int{
    };
    inline const wxString GetFormatString(PictureFormat format){
        switch (format){
            case FORMAT_PNG: return ".png"; break;
            case FORMAT_JPG: return ".jpg"; break;
            case FORMAT_WBP: return ".webp"; break;
            case FORMAT_ASCII: return ".asc"; break;
            case FORMAT_BMP: return ".bmp"; break;
            case FORMAT_SVM: return ".svm"; break;
        }
        return "";
    }
}