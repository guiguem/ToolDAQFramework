#include <string>
#include "ToolChain.h"
#include "DummyTool.h"
#include <iostream>

int main(int argc, char* argv[]){


	Factory::showClasses();
    
  std::string conffile;
  if (argc==1)conffile="configfiles/Dummy/ToolChainConfig";
  else conffile=argv[1];

    ToolChain tools(conffile);

    std::cout << "Done here" << std::endl;
  
  return 0;
  
}
