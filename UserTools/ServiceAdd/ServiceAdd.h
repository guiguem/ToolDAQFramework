#ifndef ServiceAdd_H
#define ServiceAdd_H

#include <string>
#include <iostream>

#include "Tool.h"

#include <boost/uuid/uuid.hpp>            // uuid class                                                                     
#include <boost/uuid/uuid_generators.hpp> // generators                                                                     
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.        

class ServiceAdd : public Tool::Registrar<ServiceAdd> {


 public:

  ServiceAdd();
  bool Initialise(std::string configfile,DataModel &data) override;
  bool Execute() override;
  bool Finalise() override;


 private:





};


#endif
