#include "ServiceAdd.h"

bool ServiceAdd::Initialise(std::string configfile, DataModel &data)
{

    if (configfile != "")
        m_variables.Initialise(configfile);
    //m_variables.Print();

    m_data = &data;

    zmq::socket_t Ireceive(*m_data->context, ZMQ_PUSH);
    Ireceive.connect("inproc://ServicePublish");

    boost::uuids::uuid m_UUID;
    m_UUID = boost::uuids::random_generator()();
    std::stringstream test;
    test << "Add "
         << "testservice " << m_UUID << " 1111 "
         << "0";
    zmq::message_t send(test.str().length());
    snprintf((char *)send.data(), test.str().length(), "%s", test.str().c_str());
    Ireceive.send(send);

    return true;
}

bool ServiceAdd::Execute()
{

    return true;
}

bool ServiceAdd::Finalise()
{

    zmq::socket_t Ireceive(*m_data->context, ZMQ_PUSH);
    Ireceive.connect("inproc://ServicePublish");
    std::stringstream test;
    test << "Delete "
         << "testservice ";
    zmq::message_t send(test.str().length() + 1);
    snprintf((char *)send.data(), test.str().length() + 1, "%s", test.str().c_str());
    Ireceive.send(send);

    return true;
}
