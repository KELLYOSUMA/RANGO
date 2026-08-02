#pragma once 
#include "Events.hpp"
#include "Window.h"
#include <string>
#include <sstream>
#include <utility>
namespace RANGO {
    class ApplicationEvent : public Event{
        private:
            const Window m_Window;
            unsigned int m_WindowID;
            unsigned int m_ApplicationVersion;
        public:
            EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication);
            ApplicationEvent(const Window& window,unsigned int windowID) : m_WindowID(windowID),m_Window(window){};
            virtual ~ApplicationEvent();
            virtual unsigned int GetWindowID() {return m_WindowID;};
            unsigned int GetApplicationVersion()    {return m_ApplicationVersion;}
        
    };
    class ApplicationCloseEvent : public ApplicationEvent{
        private:
        public:
            EVENT_CLASS_TYPE(WindowClose);
            ApplicationCloseEvent(const Window& window,unsigned int windowID): ApplicationEvent(window,windowID){};
            ~ApplicationCloseEvent();
            std::string ToString() {
                std::stringstream ss;
                ss<<"Window Closed event ID:"<<ApplicationEvent::GetWindowID()<<'\n';
                return ss.str();
            }
    };
    
    class ApplicationResizeEvent : public ApplicationEvent{
        private:
            std::pair<int, int> m_Dimensions;
        public:
            EVENT_CLASS_TYPE(WindowResize);
            ApplicationResizeEvent(const int Height,const int Width,const Window& window,unsigned int windowID): ApplicationEvent(window,windowID){
                 std::pair<int, int> Dimensions(Height,Width);
                 m_Dimensions = Dimensions;
                
            };
            ~ApplicationResizeEvent();
            std::string ToString() {
                std::stringstream ss;
                ss<<"Window Resized event ID:"<<ApplicationEvent::GetWindowID()<<m_Dimensions.first<<m_Dimensions.second<<'\n';
                return ss.str();
            }
            inline std::pair<int,int> GetDimensions(){
                return m_Dimensions;
            } 
    };
    class AppUpdateEvent : public ApplicationEvent{
    public:
        //very later in my program yohh
        AppUpdateEvent(Window& window,unsigned int windowID) : ApplicationEvent(window,windowID){};
        ~AppUpdateEvent();
        unsigned int GetVersion(){
            return ApplicationEvent::GetApplicationVersion();
        } 
    };
};