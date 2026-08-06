#pragma once
#include "Base.h"
#include "Window.h"
#include <memory>

namespace RANGO {
    class Application : public Base{
    public:
        
        Application(){};
        virtual ~Application(){};
        virtual void Init(){};
        virtual void Run(){};
        virtual void OnEvent(){};
        virtual void Update(){};
    private:
        bool m_running ;

    };
    // this is going to be defined in the application section
    
}