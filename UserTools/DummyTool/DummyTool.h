#ifndef DummyTool_H
#define DummyTool_H

#include <string>
#include <iostream>

#include "DataModel.h"
#include "Tool.h"

class DummyTool : public Tool::Registrar<DummyTool>
{

  public:
    DummyTool(std::string x)
    {
        std::cout << "Derived constructor" << std::endl;
    }

  public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override;
    bool Finalise() override;
    void Print() override
    {
        std::cout << "Hello DummyTool" << std::endl;
        std::cout << "Hello" << std::endl;
    }

  private:
    int m_verbose;
};

#endif
