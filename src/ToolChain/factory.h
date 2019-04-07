#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include <cstdlib>
#include <cxxabi.h>

// std::string demangle(const char *name)
// {

//     int status = -4; // some arbitrary value to eliminate the compiler warning

//     std::shared_ptr<char, void (*)(void *)> res{
//         abi::__cxa_demangle(name, NULL, NULL, &status), std::free};

//     return (status == 0) ? res.get() : name;
// }

template <class Base, class... Args>
class Factory
{
  public:
    template <class... T>
    static std::shared_ptr<Base> make(const std::string &s, T &&... args)
    {
        return data().at(s)(std::forward<T>(args)...);
    }

    template <class T>
    struct Registrar : Base
    {
        friend T;

        static bool registerT()
        {
            int status = -4; // some arbitrary value to eliminate the compiler warning

            std::unique_ptr<char, void (*)(void *)> res{
                abi::__cxa_demangle(typeid(T).name(), NULL, NULL, &status), std::free};
            const auto name = (status == 0) ? res.get() : typeid(T).name();
            std::cout << "Here\t" << name << std::endl;
            Factory::data()[name] = [](Args... args) -> std::shared_ptr<Base> {
                std::cout << "There" << std::endl;
                return std::make_shared<T>(std::forward<Args>(args)...);
            };
            std::cout << "Registered " << name << " as " << typeid(T).name() << std::endl;
            return true;
        }
        static bool registered;

      private:
        Registrar() : Base(Key{}) { (void)registered; }
    };

    friend Base;

  private:
    class Key
    {
        Key(){};
        template <class T>
        friend struct Registrar;
    };
    using FuncType = std::shared_ptr<Base> (*)(Args...);
    Factory() = default;

    static auto &data()
    {
        static std::unordered_map<std::string, FuncType> s;
        return s;
    }
};

template <class Base, class... Args>
template <class T>
bool Factory<Base, Args...>::Registrar<T>::registered =
    Factory<Base, Args...>::Registrar<T>::registerT();

#endif