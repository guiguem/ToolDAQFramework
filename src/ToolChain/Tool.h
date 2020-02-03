#ifndef TOOL_H
#define TOOL_H

#include <string>

#include "DataModel.h"
#include "Store.h"
#include "Factory.h"
// #include "ObjectBox.h"

#include <iostream>

class Tool
{

public:
    Tool() { };
    virtual bool Initialise(std::string configfile, DataModel &data) {return false;};
    // {
    //     std::cout << "Base Initialise" << std::endl;
    //     return true;
    // };
    virtual bool Execute() {return false;};
    // {
    //     std::cout << "Base Execute" << std::endl;
    //     return true;
    // };
    virtual bool Finalise() {return false;};
    // {
    //     std::cout << "Base Finalise" << std::endl;
    //     return true;
    // };
    // virtual ~Tool() = 0;
    // { std::cout << "Base destructor" << std::endl; };
    virtual void Print()
    {
        std::cout << "Hello Tool" << std::endl;
    }

protected:
    Store m_variables;
    // ObjectBox m_objectbox;
    DataModel *m_data;
    template <typename T>
    void Log(T message, int messagelevel = 1, int verbosity = 1) { m_data->Log->Log(message, messagelevel, verbosity); }
};


// Register Base class 
// namespace {
// 	// Anonymous namespace is used to make the definitions here private to the current
// 	// compilation unit (current file). It is equivalent to the old C static keyword.
// 	// It could be placed at Base.cpp 
// 	ConcreteFactory<Tool,Tool> factoryTool("Tool");
// }

// Register Base class
// namespace
// {
// // Anonymous namespace is used to make the definitions here private to the current
// // compilation unit (current file). It is equivalent to the old C static keyword.
// // It could be placed at Base.cpp
// ConcreteFactory<Tool> factoryTool("Tool");
// } // namespace

// REGISTER_FACTORY(Tool)


#endif
