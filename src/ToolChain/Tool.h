#ifndef TOOL_H
#define TOOL_H

#include <string>

#include "DataModel.h"
#include "Store.h"
#include "Factory.h"
#include "ObjectBox.h"

#include <iostream>

class Tool : public Factory<Tool, std::string>
{

  public:
    Tool(): m_objectbox() { std::cout << "Base Tool constructor" << std::endl; };
    Tool(Key):m_objectbox() { std::cout << "Base Tool constructor" << std::endl; };
    virtual bool Initialise(std::string configfile, DataModel &data) = 0;
    // {
    //     std::cout << "Base Initialise" << std::endl;
    //     return true;
    // };
    virtual bool Execute() = 0;
    // {
    //     std::cout << "Base Execute" << std::endl;
    //     return true;
    // };
    virtual bool Finalise() = 0;
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
    ObjectBox m_objectbox;
    DataModel *m_data;
    template <typename T>
    void Log(T message, int messagelevel = 1, int verbosity = 1) { m_data->Log->Log(message, messagelevel, verbosity); }

  private:
};

#endif
