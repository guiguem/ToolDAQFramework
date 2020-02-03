#include "ObjectBox.h"

std::shared_ptr<SerialisableObject> ObjectBox::CreateSerialObject(std::string objType, std::string objName)
{
    return dynamic_cast<std::shared_ptr<SerialisableObject>(*)>(Factory::makeShared(objType));
    // return SerialisableObject::make(objType, objName);
}