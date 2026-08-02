#pragma once 
#include "Events.hpp"
#include "MouseCodes.h"
#include <cstdint>
#include <iostream>
#include <sstream>
namespace RANGO{
    class MouseEvents : public Event{
    private:
        MouseCode m_MouseCode;
    public:
        virtual MouseCode GetMouseCode() {
            return m_MouseCode;
        } 
        MouseEvents(MouseCode& mousecode) :  m_MouseCode(mousecode){};
        ~MouseEvents();
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryMouseButton | EventCategory::EventCategoryInput);
        
    };
    class MousePressed : public MouseEvents {
       private:
           bool IsRepeat;
       public:
           MousePressed(MouseCode& mousecode,bool IsRepeat): MouseEvents(mousecode),IsRepeat(IsRepeat){};
           ~MousePressed();
           EVENT_CLASS_TYPE(MouseButtonPressed);
           bool IsRepeating()   {return IsRepeat;};
           virtual std::string ToString(){
               std::stringstream ss;
               ss << "MouseCode Pressed: " << static_cast<uint32_t>(MouseEvents::GetMouseCode()) << '\n';
               return ss.str();
           };
    };
    class MouseReleased : public MouseEvents {
       public:
           MouseReleased(MouseCode& mousecode): MouseEvents(mousecode){};
           ~MouseReleased();
           EVENT_CLASS_TYPE(MouseButtonReleased);
           virtual std::string ToString(){
               std::stringstream ss;
               ss << "Mouse code Released : " << static_cast<uint32_t>(MouseEvents::GetMouseCode()) << '\n';
               return ss.str();
           };
    };
    class MouseScrolled : public MouseEvents {
       public:
           MouseScrolled(MouseCode& mousecode): MouseEvents(mousecode){};
           ~MouseScrolled();
           EVENT_CLASS_TYPE(MouseButtonScrolled);
           virtual std::string ToString(){
               std::stringstream ss;
               ss << "MouseScrolled "<< '\n';
               return ss.str();
           };
    };
       
}