#pragma once 
#include "Base.h"
#include "Events.hpp"
namespace RANGO{
    class layer{
        bool m_IsOverlay;
        std::string m_name ;
        unsigned int index;
        public:
           layer(const char* name = "layer",bool IsOverlay = false):m_IsOverlay(IsOverlay),m_name(name){} ;
           virtual ~layer();
           virtual void OnAttach(){};
           virtual void OnDattach(){};
           virtual void OnUpdate(){};
           bool IsOverlay() const {return m_IsOverlay;}
           virtual void OnImGuiDraw(){};
           virtual void OnEvent(Event& e){};
           inline const virtual std::string& GetName() const {return m_name;}
           
    };
}