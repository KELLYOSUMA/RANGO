#pragma once
#include "Headers.h"
#include "layer.h"
#include "logger.h"
#include <iostream>

namespace RANGO {

    class GraphicsContext{
        GLFWwindow* m_window;
        bool IsInitialized;
        
        public:
            GraphicsContext(GLFWwindow* window);
            ~GraphicsContext();
            bool Initialize();
            bool IsCreated();
    };
}
