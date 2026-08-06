#include "LinuxWindow.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include <cstdint>
#include "GraphicsContext.h"


namespace RANGO {
    bool LinuxWindow::S_GLFWInitialized = false;
    LinuxWindow::~LinuxWindow(){
        
    }
    void LinuxWindow::GLFWInit(){
        if (!S_GLFWInitialized){
            if(!glfwInit()){
                std::cout<<"GLFW FAILED TO INITIALIZE!!"<< std::endl;;
            }
        }
    }
    
    void LinuxWindow::Init(){
        glfwInit();
        nativewindow = glfwCreateWindow(m_props.Width, m_props.Height, m_props.Title, NULL, NULL);
        GraphicsContext context(nativewindow);
        context.Initialize();
    }       
    void LinuxWindow::CreateNativeWindow(){

    }
    uint32_t LinuxWindow::GetWidth()const{
        return m_props.Width;
    }
    uint32_t LinuxWindow::GetHeight() const{
        return m_props.Height;
    }
}