#include "GraphicsContext.h"
#include "Headers.h"




namespace RANGO {
    GraphicsContext::GraphicsContext(GLFWwindow* window): m_window(window){};
    bool GraphicsContext::Initialize(){
        if (m_window == nullptr){
            std::cout << "You passed a null ptr as the the window for the context \n";
            return false ;
        }
        //Initialize GLEW modern specification for OpenGL
        if(!glewInit()){
            std::cout << "GLEW failed to initialize"<<std::endl;
        }


        //Context creation hehehe
        
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwMakeContextCurrent(m_window);
        return true;
    }
    bool GraphicsContext::IsCreated(){
        if(glfwGetCurrentContext() == m_window){
            std::cout<< "There is a Current Graphics context\n";
            return true;
        }
        std::cout << "No current context Created\n";
        return false;
    }
    GraphicsContext::~GraphicsContext(){
        
    }
};

