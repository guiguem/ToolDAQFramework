#include "ObjectBox.h"

std::shared_ptr<SerialisableObject> ObjectBox::CreateSerialObject(std::string objType, std::string objName)
{
    return SerialisableObject::make(objType, objName);
}