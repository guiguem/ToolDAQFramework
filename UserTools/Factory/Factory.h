#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include "Tool.h"

virtual Tool* Factory(std::string tool);

#endif
