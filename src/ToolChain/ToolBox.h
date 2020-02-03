#ifndef TOOLBOX_H
#define TOOLBOX_H
#include "Tool.h"

#include <iostream>

class ToolBox
{
    public:
    ToolBox(){}
    // Tool* CreateTool(std::string toolName, std::string noise);
    std::shared_ptr<Tool> CreateTool(std::string toolName, std::string noise);
};

#endif