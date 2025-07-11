#pragma once
#include <wx/wx.h>
#include "WindowFrame.h"

class App : public wxApp{
public:
    bool OnInit();
    virtual void OnFatalException() override;
};