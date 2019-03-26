#include "ToolBox.h"

std::unique_ptr<Tool> ToolBox::CreateTool(std::string toolName, std::string noise)
{
    std::cout << toolName << "\t" << noise << std::endl;
    return Tool::make(toolName, noise);
};