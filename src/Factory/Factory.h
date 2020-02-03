#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <iostream>
#include <string>
#include <map>
#include <memory>

#include <cstdlib>
#include <cxxabi.h>

// template <class Base, class... Args>
// class Factory
// {
// public:
//     template <class... T>
//     static std::shared_ptr<Base> make(const std::string &s, T &&... args)
//     {
//         return data().at(s)(std::forward<T>(args)...);
//     }
//     // template <class... T>
//     // static std::shared_ptr<Base> make(const std::string &s)
//     // {
//     //     return data().at(s)(std::forward<T>(args)...);
//     // }

//     template <class T>
//     struct Registrar : Base
//     {
//         friend T;

//         static bool registerT()
//         {
//             int status = -4; // some arbitrary value to eliminate the compiler warning

//             std::unique_ptr<char, void (*)(void *)> res{
//                 abi::__cxa_demangle(typeid(T).name(), NULL, NULL, &status), std::free};
//             const auto name = (status == 0) ? res.get() : typeid(T).name();
//             Factory::data()[name] = [](Args... args) -> std::shared_ptr<Base> {
//                 return std::make_shared<T>(std::forward<Args>(args)...);
//             };
//             std::cout << "Factory: Registered " << name << " as " << typeid(T).name() << std::endl;
//             return true;
//         }
//         static bool registered;

//     private:
//         Registrar() : Base(Key{}) { (void)registered; }
//     };

//     friend Base;

// private:
//     class Key
//     {
//         Key(){};
//         template <class T>
//         friend struct Registrar;
//     };
//     using FuncType = std::shared_ptr<Base> (*)(Args...);
//     Factory() = default;

//     static auto &data()
//     {
//         static std::unordered_map<std::string, FuncType> s;
//         return s;
//     }
// };

// template <class Base, class... Args>
// template <class T>
// bool Factory<Base, Args...>::Registrar<T>::registered =
//     Factory<Base, Args...>::Registrar<T>::registerT();

// #################
// Try and use this instead
// https://rextester.com/ILKI85678

// File:   factory-pattern1.cpp 
// Brief:  Factory design pattern with self registering of derived classes.
// Author: Caio Rodrigues
//=======================================================================

#include <iostream>
#include <string>
#include <map>
#include <memory>

// Macro for class registration 
#define REGISTER_FACTORY(baseClass,derivedClass) \
	namespace { auto registry_ ## derivedClass = ConcreteFactory<baseClass,derivedClass>(#derivedClass);  }

          // ========>>> Forward declarations =====//
class Base;

          // ============  Factory Infrastructure =========== //

template<typename BaseClass>
class Factory{
private:
	using FactoryMap = std::map<std::string, Factory*>;
	// Force global variable to be initialized, thus it avoid
	// the inialization order fisaco. 
	static auto getRegister() -> FactoryMap& {
		static FactoryMap classRegister{};
		return classRegister;
	}
public:	
	/** Register factory object of derived class */
	static
	auto registerFactory(const std::string& name, Factory* factory) -> void {
		auto& reg = Factory::getRegister();
		reg[name] = factory;
	}
	/** Show all registered classes */
	static
	auto showClasses() -> void {
		std::cout << " Registered classes. " << "\n";
		std::cout << " =================== " << "\n";
		for(const auto& pair: Factory::getRegister())
			std::cout << " + " << pair.first << "\n";
	}		
	/**  Construct derived class returning a raw pointer */
	static
	auto makeRaw(const std::string& name) -> BaseClass* {
		auto it = Factory::getRegister().find(name);
		if(it != Factory::getRegister().end())
			return it->second->construct();
		return nullptr;
	}
	
    /** Construct derived class returning an unique ptr  */
	static
	auto makeUnique(const std::string& name) -> std::unique_ptr<BaseClass>{
		return std::unique_ptr<BaseClass>(Factory::makeRaw(name));
	}
	
    /** Construct derived class returning an shared ptr  */
	static
	auto makeShared(const std::string& name) -> std::shared_ptr<BaseClass>{
		return std::shared_ptr<BaseClass>(Factory::makeRaw(name));
	}

	// Destructor 
	virtual
	~Factory() = default;
	
	virtual
	auto construct() const -> BaseClass* = 0;
};

template<typename BaseClass,typename DerivedClass>
class ConcreteFactory: Factory<BaseClass>{
public:
	// Register this global object on the Factory register 
	ConcreteFactory(const std::string& name){
		std::cerr << " [TRACE] " << " Registered Class = " << name << "\n";
		Factory<BaseClass>::registerFactory(name, this);
	}
	auto construct() const -> BaseClass* {
		return new DerivedClass;
	}	
};


// ========>>> Factory Products - or concrete classes created by factory <=======//

// class Base{
// public:
// 	Base() = default;
// 	// Destructor of base class must always be virtual 
// 	virtual ~Base() = default;   
// 	virtual auto getType() const -> std::string {
//       return "Base";
//    }	
//    void showType(){
//       std::cout << "Class type = " << this->getType() << "\n";
//    }
// };

// // Register Base class 
// namespace {
// 	// Anonymous namespace is used to make the definitions here private to the current
// 	// compilation unit (current file). It is equivalent to the old C static keyword.
// 	// It could be placed at Base.cpp 
// 	ConcreteFactory<Base,Base> factoryBase("Base");
// }

// class DerivedA: public Base{
// public:
//     DerivedA(){}
//     auto getType() const  -> std::string {
//        return "DerivedA";
//     }
// };

// //  Registration with macro. 
// REGISTER_FACTORY(Base,DerivedA);

// class DerivedB: public Base{
// public:
// 	DerivedB(){}
// 	auto getType() const -> std::string {
//       return "DerivedB";
//    }
// };

// REGISTER_FACTORY(Base,DerivedB);

// class DerivedC: public DerivedB{
// public:
// 	DerivedC(){}
// 	auto getType() const -> std::string {
//       return "DerivedC";
//    }
// };

// REGISTER_FACTORY(Base,DerivedC);

// // Disadvantage: Adding new derived classes to this function requires code modification
// auto simpleFactory(const std::string& name) -> std::unique_ptr<Base> {
// 	if(name == "Base")
// 		return std::make_unique<Base>();
// 	if(name == "DerivedA")
// 		return std::make_unique<DerivedA>();
// 	if(name == "DerivedB")
// 		return std::make_unique<DerivedB>();
// 	return nullptr;
// }

// int main(){

// 	Factory::showClasses();
// 	std::cout << "\n";
// 	std::unique_ptr<Base> objBase = Factory::makeUnique("Base");
// 	std::cout << " type of objBase = " << objBase->getType() << "\n";

// 	std::unique_ptr<Base> objDA = Factory::makeUnique("DerivedA");
// 	std::cout << " type of derivedA = " << objDA->getType() << "\n";

// 	std::unique_ptr<Base> objDB = Factory::makeUnique("DerivedB");
// 	std::cout << " type of derivedB = " << objDB->getType() << "\n";
    
// 	std::unique_ptr<Base> objDC = Factory::makeUnique("DerivedC");
// 	std::cout << " type of derivedC = " << objDC->getType() << "\n";

// 	std::unique_ptr<Base> objDD = Factory::makeUnique("Derived-error");
// 	if(!objDC)
// 		std::cout << " ==> Error: object not found in factory" << '\n';
	
// 	return 0;
// }



// class Base;

// // Macro for class registration
// #define REGISTER_FACTORY(derivedClass)                                           \
//     namespace                                                                    \
//     {                                                                            \
//     auto registry_##derivedClass = ConcreteFactory<derivedClass>(#derivedClass); \
//     }

// // ========>>> Forward declarations =====//
// // class Base;
// // class DerivedA;
// // class DerivedB;

// // ============  Factory Infrastructure =========== //

// class Factory
// {
// private:
//     using FactoryMap = std::map<std::string, Factory *>;
//     // Force global variable to be initialized, thus it avoid
//     // the inialization order fisaco.
//     static auto getRegister() -> FactoryMap &
//     {
//         static FactoryMap classRegister{};
//         return classRegister;
//     }

// public:
//     /** Register factory object of derived class */
//     static auto registerFactory(const std::string &name, Factory *factory) -> void
//     {
//         auto &reg = Factory::getRegister();
//         reg[name] = factory;
//     }
//     /** Show all registered classes */
//     static auto showClasses() -> void
//     {
//         std::cout << " Registered classes. "
//                   << "\n";
//         std::cout << " =================== "
//                   << "\n";
//         for (const auto &pair : Factory::getRegister())
//             std::cout << " + " << pair.first << "\n";
//     }
//     /**  Construct derived class returning a raw pointer */
//     static auto makeRaw(const std::string &name) -> Base *
//     {
//         auto it = Factory::getRegister().find(name);
//         if (it != Factory::getRegister().end())
//             return it->second->construct();
//         return nullptr;
//     }

//     /** Construct derived class returning an unique ptr  */
//     virtual auto makeUnique(const std::string &name) -> std::unique_ptr<Base>
//     {
//         return std::unique_ptr<Base>(Factory::makeRaw(name));
//     }

//     /** Construct derived class returning an shared ptr  */
//     virtual auto makeShared(const std::string &name) -> std::shared_ptr<Base>
//     {
//         return std::shared_ptr<Base>(Factory::makeRaw(name));
//     }

//     // Destructor
//     virtual ~Factory() = default;

//     virtual auto construct() const -> Base * = 0;
// };

// template <typename DerivedClass>
// class ConcreteFactory : Factory
// {
// public:
//     // Register this global object on the Factory register
//     ConcreteFactory(const std::string &name)
//     {
//         std::cerr << " [TRACE] "
//                   << " Registered Class = " << name << "\n";
//         Factory::registerFactory(name, this);
//     }
//     auto construct() const -> Base *
//     {
//         return new DerivedClass;
//     }
// };

// // ========>>> Factory Products - or concrete classes created by factory <=======//

// class Base
// {
// public:
//     Base() = default;
//     // Destructor of base class must always be virtual
//     virtual ~Base() = default;
//     virtual auto getType() const -> std::string
//     {
//         return "Base";
//     }
//     void showType()
//     {
//         std::cout << "Class type = " << this->getType() << "\n";
//     }
// };

// // Register Base class
// namespace
// {
// // Anonymous namespace is used to make the definitions here private to the current
// // compilation unit (current file). It is equivalent to the old C static keyword.
// // It could be placed at Base.cpp
// ConcreteFactory<Base> factoryBase("Base");
// } // namespace

#endif
