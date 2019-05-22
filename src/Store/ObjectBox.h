#ifndef OBJECTBOX_H
#define OBJECTBOX_H

#include "SerialisableObject.h"

#include <iostream>

class ObjectBox
{
    public:
    ObjectBox(){}
    std::shared_ptr<SerialisableObject> CreateSerialObject(std::string objType, std::string objName);
};

#endif