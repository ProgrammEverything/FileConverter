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

    inline const wxString GetPictureFormat(TypeFormat format){
        switch (format){
            case FORMAT_PNG: return ".png";  
            case FORMAT_JPG: return ".jpg";   
            case FORMAT_WBP: return ".webp";  
            case FORMAT_ASCII: return ".asc"; 
            case FORMAT_BMP: return ".bmp";   
            case FORMAT_SVM: return ".svm";   
        }
        return "";
    }
    inline const wxString GetMovieFormat(TypeFormat format){
        switch(format){
            case FORMAT_3GP:   return ".3gp"; 
            case FORMAT_ASF:   return ".asf"; 
            case FORMAT_AVI:   return ".avi"; 
            case FORMAT_FLV:   return ".flv"; 
            case FORMAT_MKV:   return ".mkv"; 
            case FORMAT_MOV:   return ".mov"; 
            case FORMAT_MP4:   return ".mp4"; 
            case FORMAT_MPEG:  return ".mpeg";
            case FORMAT_MPG:   return ".mpg"; 
            case FORMAT_MXF:   return ".mxf"; 
            case FORMAT_WEBM:  return ".webm";
            case FORMAT_WMV:   return ".wmv";
        }
        return "";
    }
    inline bool isMovieFormat(TypeFormat str){
        return GetMovieFormat(str) == "";
    }
    inline bool isPictureFormat(TypeFormat str){
        return GetPictureFormat(str) == "";
    }
    enum Flags {

    };
    struct MovieString {const char* from; const char* to; };
    struct PictureString {const char* from; const char* to; };

}