#ifndef TOOL_H
#define TOOL_H

#include <string>

// #include "Store.h"
#include "DataModel.h"

class Store;

class Tool{
  
 public:
  
  virtual bool Initialise(std::string configfile,DataModel &data){};
  virtual bool Execute(){};
  virtual bool Finalise(){};
  virtual ~Tool(){};
  
 protected:
  
  Store m_variables;
  DataModel *m_data;
  template <typename T>  void Log(T message, int messagelevel=1, int verbosity=1){m_data->Log->Log(message,messagelevel,verbosity);}
  
 private:
  
  
  
  
  
};

#endif
