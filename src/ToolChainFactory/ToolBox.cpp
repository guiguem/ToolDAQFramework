#include "ToolBox.h"

std::unique_ptr<ToolTest> ToolBox::CreateTool(std::string toolName, std::string noise)
{
    std::cout << toolName << "\t" << noise << std::endl;
    return ToolTest::make(toolName, noise);
};