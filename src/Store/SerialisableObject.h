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

class SerialisableObject
{

    friend class boost::serialization::access;

public:
    SerialisableObject() { };
    virtual bool Print() { return 0;};
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


// // Register SerialisableObject class 
// namespace {
// 	// Anonymous namespace is used to make the definitions here private to the current
// 	// compilation unit (current file). It is equivalent to the old C static keyword.
// 	// It could be placed at Base.cpp 
// 	ConcreteFactory<SerialisableObject,SerialisableObject> factorySerialisableObject("SerialisableObject");
// }

// REGISTER_FACTORY(SerialisableObject)

#endif
