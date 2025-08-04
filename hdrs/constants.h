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

    inline const wxArrayString movie_formats = {
        "3GP Format",
        "ASF Format",
        "AVI Format",
        "FLV Format",
        "MKV Format",
        "MOV Format",
        "MP4 Format",
        "MPEG Format",
        "MPG Format",
        "MXF Format",
        "WEBM Format",
        "WMV Format"
    };

    enum TypeFormat : int {
        FORMAT_PNG   = 0x1,
        FORMAT_JPG   = 0x2,
        FORMAT_WBP   = 0x4,
        FORMAT_ASCII = 0x8,
        FORMAT_BMP   = 0x10,
        FORMAT_SVM   = 0x20,

        FORMAT_3GP   = 0x40,
        FORMAT_ASF   = 0x80,
        FORMAT_AVI   = 0x100,
        FORMAT_FLV   = 0x200,
        FORMAT_MKV   = 0x400,
        FORMAT_MOV   = 0x800,
        FORMAT_MP4   = 0x1000,
        FORMAT_MPEG  = 0x2000,
        FORMAT_MPG   = 0x4000,
        FORMAT_MXF   = 0x8000,
        FORMAT_WEBM  = 0x10000,
        FORMAT_WMV   = 0x20000
    };

    inline const wxString GetFormatString(TypeFormat format){
        switch (format){
            case FORMAT_PNG: return ".png";   break;
            case FORMAT_JPG: return ".jpg";   break;
            case FORMAT_WBP: return ".webp";  break;
            case FORMAT_ASCII: return ".asc"; break;
            case FORMAT_BMP: return ".bmp";   break;
            case FORMAT_SVM: return ".svm";   break;
            case FORMAT_3GP:   return ".3gp"; break;
            case FORMAT_ASF:   return ".asf"; break;
            case FORMAT_AVI:   return ".avi"; break;
            case FORMAT_FLV:   return ".flv"; break;
            case FORMAT_MKV:   return ".mkv"; break;
            case FORMAT_MOV:   return ".mov"; break;
            case FORMAT_MP4:   return ".mp4"; break;
            case FORMAT_MPEG:  return ".mpeg";break;
            case FORMAT_MPG:   return ".mpg"; break;
            case FORMAT_MXF:   return ".mxf"; break;
            case FORMAT_WEBM:  return ".webm";break;
            case FORMAT_WMV:   return ".wmv"; break;
        }
        return "";
    }
    enum Flags {

    };
    struct MovieString {const char* from; const char* to; };
    struct PictureString {const char* from; const char* to; };

}