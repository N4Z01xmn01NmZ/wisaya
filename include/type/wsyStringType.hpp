#ifndef WSYSTRINGTYPE_H
#define WSYSTRINGTYPE_H

#pragma once

#include <string>
#include <sstream>

namespace Wisaya
{

    typedef const char* wsy_cstr;            ///< const char pointer type (c string)
    typedef std::string wsy_string;          ///< std string (c++ string)
    typedef std::stringstream wsy_sstream;   ///< string stream
    
} // namespace Wisaya

#endif // WSYSTRINGTYPE_H
