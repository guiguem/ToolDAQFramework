#ifndef DummyTool_H
#define DummyTool_H

#include <string>
#include <iostream>

#include "DataModel.h"
#include "Tool.h"

class DummyTool : public Tool::Registrar<DummyTool> {


 public:

  bool Initialise(std::string configfile,DataModel &data);
  bool Execute();
  bool Finalise();


 private:

  int m_verbose;

};


#endif
