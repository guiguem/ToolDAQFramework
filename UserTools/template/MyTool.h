#ifndef MYTOOL_H
#define MYTOOL_H

#include <string>
#include <iostream>

#include "Tool.h"

class MyTool: public Tool {


 public:

  MyTool();
  bool Initialise(std::string configfile,DataModel &data) override;
  bool Execute() override;
  bool Finalise() override;


 private:





};


#endif
