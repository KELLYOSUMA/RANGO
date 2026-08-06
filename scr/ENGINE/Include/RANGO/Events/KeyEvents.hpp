#pragma once 
#include "Events.hpp"
#include "KeyCodes.h"
#include <cstdint>
#include <pthread.h>
#include <sstream>
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
            std::stringstream ss;
            ss << "KeyPressedEvent: " << static_cast<uint16_t>(KeyEvent::GetKeyCode())<< " (repeat = " << m_IsRepeat << ")";
            return ss.str();
        }
        
    private:
        bool m_IsRepeat;
    } ;
    class KeyReleased : public KeyEvent {
    public:
        KeyReleased(const KeyCode& p_keycode) : KeyEvent(p_keycode) {};
        EVENT_CLASS_TYPE(keyPressed);
        virtual std::string ToString() const override{
            std::stringstream ss;
            ss << "KeyPressedEvent: " << static_cast<uint16_t>(KeyEvent::GetKeyCode())<< "\n";
            return ss.str();
        }
    } ;
    class keyTyped : public KeyEvent {
    public:
        keyTyped(const KeyCode& keycode,bool IsRepeat) : KeyEvent(keycode),m_IsRepeat(IsRepeat){};
        ~keyTyped();
        bool IsRepeating() const    {return m_IsRepeat;}
        virtual std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << static_cast<uint16_t>(KeyEvent::GetKeyCode())<< " (repeat = " << m_IsRepeat << ")";
            return ss.str();
        }
    private:
        bool m_IsRepeat;
    };
}