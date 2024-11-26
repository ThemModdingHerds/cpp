#ifndef __TMH_TFHRES_DATA_HPP
#define __TMH_TFHRES_DATA_HPP

#include <hiberlite.h>
#include <string>

class cache_record
{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive& ar)
    {
        ar & HIBERLITE_NVP(shortname);
        ar & HIBERLITE_NVP(source_path);
    }
public:
    std::string shortname;
    std::string source_path;
};
HIBERLITE_EXPORT_CLASS(cache_record)

#endif