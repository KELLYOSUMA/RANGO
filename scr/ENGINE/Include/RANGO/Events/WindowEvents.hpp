#pragma once 
#include "Events.hpp"
#include "Window.h"
#include <string>
#include <sstream>
#include <utility>
namespace RANGO {
    class WindowEvent : public Event{
        private:
            const Window m_Window;
            unsigned int m_WindowID;
        public:
            EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication);
            WindowEvent(const Window& window,unsigned int windowID) : m_WindowID(windowID),m_Window(window){};
            virtual ~WindowEvent();
            virtual unsigned int GetWindowID() {return m_WindowID;};
    };
    class WindowCloseEvent : public WindowEvent{
        private:
        public:
            EVENT_CLASS_TYPE(WindowClose);
            WindowCloseEvent(const Window& window,unsigned int windowID): WindowEvent(window,windowID){};
            ~WindowCloseEvent();
            std::string ToString() {
                std::stringstream ss;
                ss<<"Window Closed event ID:"<<WindowEvent::GetWindowID()<<'\n';
                return ss.str();
            }
    };
    
    class WindowResizeEvent : public WindowEvent{
        private:
            std::pair<int, int> m_Dimensions;
        public:
            EVENT_CLASS_TYPE(WindowResize);
            WindowResizeEvent(const int Height,const int Width,const Window& window,unsigned int windowID): WindowEvent(window,windowID){
                 std::pair<int, int> Dimensions(Height,Width);
                 m_Dimensions = Dimensions;
                
            };
            ~WindowResizeEvent();
            std::string ToString() {
                std::stringstream ss;
                ss<<"Window Resized event ID:"<<WindowResizeEvent::GetWindowID()<<m_Dimensions.first<<m_Dimensions.second<<'\n';
                return ss.str();
            }
            inline std::pair<int,int> GetDimensions(){
                return m_Dimensions;
            } 
    };
};