#pragma once
#include "Macros.h"
namespace RANGO{
    //define the macros i will use to get the category flags and the name and type of the events
                                    
    enum class EventType{
    None = 0,
    WindowClose,WindowResize,WindowMoved,WindowFocus,WindowLostFocus,
    MouseButtonPressed,MouseButtonReleased,MouseButtonScrolled,
    keyPressed,keyReleased,KeyTyped,
    AppUpdate,AppTick,AppRender,  
    };
    
    enum class EventCategory{
        None = 0,
        EventCategoryMouse = BIT(0),
        EventCategoryKeyboard = BIT(1),
        EventCategoryApplication = BIT(2),
        EventCategoryMouseButton = BIT(3),
        EventCategoryInput = BIT(4),
    };

    class Event{
        public:
            Event() = default;
            virtual ~Event() = default;
            bool Handled = false;
            virtual const char* GetName() const = 0;
            virtual EventCategory GetCategoryFlags() const =0;
            virtual EventType GetEventType() const =0;
            //virtual void OnEvent(Event& Event);
            //virtual void DispatchEvent(Event& Event);
            //virtual void Determine_Event(Event& Event);
    };
    
    inline constexpr EventCategory operator|(EventCategory lhs, EventCategory rhs){
        return static_cast<EventCategory>(static_cast<int>(lhs),static_cast<int>(rhs));
    }


    class EventDispatcher{
    public:
        EventDispatcher(Event& event)
            : m_event(event)
        {};
        
        template<typename T,typename F>
        bool Dispatch(const F& func){
            if (m_event.GetEventType() == T::StaticEventType()){
                m_event.Handled |= func(static_cast<T&>(m_event));
                return true;
            }
            return false;
        }
    private:
        Event& m_event;
    };           
    #define EVENT_CLASS_CATEGORY(category) virtual EventCategory GetCategoryFlags() const override {return category;};
    #define EVENT_CLASS_TYPE(type) static EventType StaticEventType()    {return EventType::type;}\
                                    virtual EventType GetEventType()    {return StaticEventType();}\
                                    virtual const char* GetName()   {return #type;}
};
