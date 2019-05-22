#ifndef SERIALISABLEOBJECT_H
#define SERIALISABLEOBJECT_H

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>

#include "Factory.h"

class SerialisableObject: public Factory<SerialisableObject, std::string>
{

    friend class boost::serialization::access;

  public:

    SerialisableObject() { std::cout << "Base constructor" << std::endl; };
    SerialisableObject(Key) { std::cout << "Base constructor" << std::endl; };
    virtual bool Print() = 0;
    virtual ~SerialisableObject(){};
    bool serialise;

  protected:
    std::string type;
    std::string version;

    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        if (serialise)
        {
            ar &type;
            ar &version;
        }
    }

  private:
};

#endif
