#pragma once
#include "Base.h"
#include "Events.hpp"
#include <cstdint>
#include <memory>
#include <type_traits>
#include "layer.h"

namespace RANGO{
    
    struct WindowProps{
        const char* Title;
        uint32_t Width;
        uint32_t Height;
        
        WindowProps():Width(600),Height(800),Title("RANGO"){};
        ~WindowProps() = default;
    };
    class Window : public Base {
    public:
        static scope<Window> CreateWindow(const WindowProps& props = WindowProps());
        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;
        virtual void OnUpdate();
        virtual ~Window() override;
        Window() = default;
    private:
    };
}
