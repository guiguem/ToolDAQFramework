#ifndef Logger_H
#define Logger_H

#include <string>
#include <iostream>

#include "Tool.h"

class Logger : public Tool
{
  public:
    Logger() {std::cout << "Logger constructor" << std::endl;}

  public:
    bool Initialise(std::string configfile, DataModel &data) override;
    bool Execute() override;
    bool Finalise() override;

    void Print() override
    {
        std::cout << "Hello Logger" << std::endl;
    }

  private:
    int m_log_port;
    zmq::socket_t *LogReceiver;
};

REGISTER_FACTORY(Tool,Logger)

#endif
