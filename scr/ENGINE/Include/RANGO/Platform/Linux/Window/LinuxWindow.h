#pragma once

#include "Window.h"
#include "GraphicsContext.h"



namespace RANGO {
    class LinuxWindow: public Window{
    public:
        LinuxWindow(const WindowProps& props){
            m_props = props;
            Init();
        };
        LinuxWindow() = default;
        virtual uint32_t GetWidth() const override;
        virtual uint32_t GetHeight() const override;
        virtual void OnUpdate() override{};
        virtual void Init();
        virtual void GLFWInit();
        virtual void CreateNativeWindow();
        virtual ~LinuxWindow();
        GLFWwindow* GetNativeWindow()    {return nativewindow;};
    private:
        WindowProps m_props;
        static bool S_GLFWInitialized;
        GLFWwindow* nativewindow;
    };
}
