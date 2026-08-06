#pragma once 

#include <memory>
namespace RANGO{
    template<typename T>
    using scope = std::unique_ptr<T>;
    template<typename T,typename... Args>
    scope<T>  CreateScope(Args&& ... args){
        return std::make_unique<T>(std::forward<Args>(args)...);
    }
    class Base{
    public:
        Base();
        virtual ~Base();
    };
};