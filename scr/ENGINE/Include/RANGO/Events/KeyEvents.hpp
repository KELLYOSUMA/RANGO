#pragma once 
#include "Events.hpp"
#include "KeyCodes.h"
#include <cstdint>
#include <pthread.h>
#include <string.h>
#include <iostream>
#include <string>

namespace RANGO {
    class KeyEvent : public Event{
    private:
            KeyCode m_keyCode;
    public:
        KeyEvent(const KeyCode keycode)
            :m_keyCode(keycode){};
        ~KeyEvent();
        KeyCode GetKeyCode() const    {return m_keyCode;}
        virtual std::string ToString() const;  
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryKeyboard | EventCategory::EventCategoryInput)
    
    };
    class KeyPressed : public KeyEvent {
    public:
        KeyPressed(const KeyCode& p_keycode,bool IsRepeat) : KeyEvent(p_keycode) , m_IsRepeat(IsRepeat){};
        EVENT_CLASS_TYPE(keyPressed);
        bool Is_Repeat() const    {return m_IsRepeat;}
        virtual std::string ToString() const override{
            std::cout << "Key Pressed: " << static_cast<uint32_t>(KeyEvent::GetKeyCode()) << '\n';
        }
        
    private:
        bool m_IsRepeat;
    } ;
}