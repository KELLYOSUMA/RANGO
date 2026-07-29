#pragma once
#include "Base.h"

namespace RANGO{
    class Window : public Base{
    public:
        void Create_Wind_Init(int& width,int& height);
        void OnEvent();
        Window();
        virtual ~Window() override;
    private:
        static Window* GetWindow(){
            static Window instance;
            return &instance;
        }
    };
}
