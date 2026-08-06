#include "Engine/Engine.h"
#include "Events.hpp"
#include <X11/X.h>
#include <iostream>
#include "Window.h"
#include "LinuxWindow.h"


namespace RANGO{
    class SandBox :public Application{
        public:
            SandBox(){};
            ~SandBox(){};
        private:
            
    };
    Application* CreateApplication(){
        return new SandBox();
    }
}

int main(){
    auto app = RANGO::CreateApplication();
    RANGO::WindowProps props;
    props.Title ="hello world ";
    props.Height = 1200;
    props.Width = 600;
    RANGO::LinuxWindow lin(props);
    lin.CreateNativeWindow();
    return 0;
}