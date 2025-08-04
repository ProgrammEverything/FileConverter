#pragma once
#include <string_view>
#include <array>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <wx/string.h>
#include <unordered_map>
namespace cs{
    // inline const wxArrayString picture_formats =  {
    //     "PNG Format",
    //     "JPG Format",
    //     "Webp Format",
    //     "Ascii Format",
    //     "Bitmap Format",
    //     "SVM(CPP) Format",
    // };

    // inline const wxArrayString movie_formats = {
    //     "3GP Format",
    //     "ASF Format",
    //     "AVI Format",
    //     "FLV Format",
    //     "MKV Format",
    //     "MOV Format",
    //     "MP4 Format",
    //     "MPEG Format",
    //     "MPG Format",
    //     "MXF Format",
    //     "WEBM Format",
    //     "WMV Format"
    // };
    
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
    // For image formats
    inline const std::tuple<const TypeFormat,const wxString&,const wxString&> format_image_desc[] = {
        {FORMAT_PNG,   ".png",   "PNG FORMAT"},
        {FORMAT_JPG,   ".jpg",   "JPG FORMAT"},
        {FORMAT_WBP,   ".webp",  "WEBP FORMAT"},
        {FORMAT_ASCII, ".asc",   "ASCII FORMAT"},
        {FORMAT_BMP,   ".bmp",   "BMP FORMAT"},
        {FORMAT_SVM,   ".svm",   "SVM FORMAT"},
    };

    // For video formats
    inline const std::tuple<const TypeFormat,const wxString&,const wxString&> format_video_desc[] = {
        {FORMAT_3GP,   ".3gp",   "3GP FORMAT"},
        {FORMAT_ASF,   ".asf",   "ASF FORMAT"},
        {FORMAT_AVI,   ".avi",   "AVI FORMAT"},
        {FORMAT_FLV,   ".flv",   "FLV FORMAT"},
        {FORMAT_MKV,   ".mkv",   "MKV FORMAT"},
        {FORMAT_MOV,   ".mov",   "MOV FORMAT"},
        {FORMAT_MP4,   ".mp4",   "MP4 FORMAT"},
        {FORMAT_MPEG,  ".mpeg",  "MPEG FORMAT"},
        {FORMAT_MPG,   ".mpg",   "MPG FORMAT"},
        {FORMAT_MXF,   ".mxf",   "MXF FORMAT"},
        {FORMAT_WEBM,  ".webm",  "WEBM FORMAT"},
        {FORMAT_WMV,   ".wmv",   "WMV FORMAT"},
    };

    inline const wxString& GetPictureFormat(TypeFormat format){
        for(auto& item : format_image_desc){
            if (format == std::get<0>(item)){
                return std::get<1>(item);
            }
        }
        return wxEmptyString;
    }
    inline const wxString& GetMovieFormat(TypeFormat format){
        for(auto& item : format_video_desc){
            if (format == std::get<0>(item)){
                return std::get<1>(item);
            }
        }
        return wxEmptyString;
    }
    inline bool isMovieFormat(TypeFormat str){
        return GetMovieFormat(str) != "";
    }
    inline bool isPictureFormat(TypeFormat str){
        return GetPictureFormat(str) != "";
    }
    inline bool getTypeByExt(const wxString& ext){

    }
    enum Flags {

    };
    struct MovieString {const char* from; const char* to; };
    struct PictureString {const char* from; const char* to; };

}