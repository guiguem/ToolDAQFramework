#ifndef TOOL_H
#define TOOL_H

#include <string>

#include "DataModel.h"
#include "Store.h"
#include "factory.h"

class Tool : public Factory<Tool, std::string>
{

  public:
    Tool(Key) {};
    virtual bool Initialise(std::string configfile, DataModel &data) = 0;
    virtual bool Execute() = 0;
    virtual bool Finalise() = 0;
    virtual ~Tool(){};

  protected:
    Store m_variables;
    DataModel *m_data;
    template <typename T>
    void Log(T message, int messagelevel = 1, int verbosity = 1) { m_data->Log->Log(message, messagelevel, verbosity); }

  private:
};

#endif
