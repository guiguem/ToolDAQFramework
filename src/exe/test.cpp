#include <iostream>
#include <string>

#include "ToolBox.h"

int main()
{
    std::cout << "main" << std::endl;
    ToolBox toolbox;
    auto wrench = toolbox.CreateTool("Wrench", "splash");
    auto wrench2 = toolbox.CreateTool("Wrench", "bing");
    auto screwDriver = toolbox.CreateTool("ScrewDriver", "paff");
    return 0;
}
