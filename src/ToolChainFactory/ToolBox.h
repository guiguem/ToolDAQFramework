#ifndef TOOLBOX_H
#define TOOLBOX_H
#include "ToolTest.h"

#include <iostream>

class ToolBox
{
    public:
    ToolBox(){}
    std::unique_ptr<ToolTest> CreateTool(std::string toolName, std::string noise);
};

#endif