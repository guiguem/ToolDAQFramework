#include "ToolBox.h"

std::shared_ptr<Tool> ToolBox::CreateTool(std::string toolName, std::string noise)
{
    std::cout << toolName << "\t" << noise << std::endl;
    // return registry_Tool.construct();
    return Factory<Tool>::makeShared(toolName);
    // return std::dynamic_pointer_cast<std::shared_ptr<Tool>(registry_Tool.construct())>;
    // return Tool::make(toolName, noise);
};
