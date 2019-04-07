#ifndef Logger_H
#define Logger_H

#include <string>
#include <iostream>

#include "Tool.h"

class Logger : public Tool::Registrar<Logger>
{
  public:
    Logger(std::string x) {std::cout << "Logger constructor" << std::endl;}

  public:
    bool Initialise(std::string configfile, DataModel &data);
    bool Execute();
    bool Finalise();

    void Print() override
    {
        std::cout << "Hello Logger" << std::endl;
    }

  private:
    int m_log_port;
    zmq::socket_t *LogReceiver;
};

#endif
