#ifndef SERIALISABLEOBJECT_H
#define SERIALISABLEOBJECT_H

#include <iostream>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include "Factory.h"

class SerialisableObject : public Factory<SerialisableObject, std::string>
{

    friend class boost::serialization::access;

public:
    SerialisableObject() { };
    SerialisableObject(Key) { };
    virtual bool Print() = 0;
    virtual ~SerialisableObject(){};
    bool serialise;

protected:
    std::string type;
    std::string version;

    // Needed so we can write it into a text file (via TextWriterTool)
    friend std::ostream &operator<<(std::ostream &out, const SerialisableObject &obj)
    {
        std::cerr << "ERROR" << std::endl;
        return out;
    };

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
