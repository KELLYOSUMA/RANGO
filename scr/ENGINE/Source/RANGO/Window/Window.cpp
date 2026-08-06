#include "Base.h"
#include "LinuxWindow.h"
#include <Window.h>
#include <cstdint>
#include <memory>
#include <utility>
namespace RANGO {
    RANGO::Window::~Window(){   
        
    }
    scope<Window> Window::CreateWindow(const WindowProps& props){
        #if defined(__linux__)
            return CreateScope<LinuxWindow>(props);
        #else
            return nullptr;
        #endif
    }
    void RANGO::Window::OnUpdate(){
        
    }
};