#include "ToolBox.h"

std::shared_ptr<Tool> ToolBox::CreateTool(std::string toolName, std::string noise)
{
    std::cout << toolName << "\t" << noise << std::endl;
    return Tool::make(toolName, noise);
};

std::shared_ptr<SerialisableObject> ToolBox::CreateSerialObject(std::string objType, std::string objName)
{
    return SerialisableObject::make(objType, objName);
}