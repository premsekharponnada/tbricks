//****************************************************************************
// Tbricks STL-compatible wrapper above Paul Hsieh's SuperFastHash function.
//
// Copyright (c) 2006-2007 Tbricks AB.
//
// The wrapper defines set of functors for most common data types.
//
//****************************************************************************

#ifndef __TBRICKS__HASH__HASH_FUN__H
#define __TBRICKS__HASH__HASH_FUN__H

#include <cstring>

#include "hash/SuperFastHash.h"


// \namespace tbricks
namespace tbricks {

// \namespace types
namespace types {

template<class KEY> struct hash { };

template<> struct hash<char *>
{
    size_t operator()(const char * data) const
    { return SuperFastHash(data, std::strlen(data)); }
};

template<> struct hash<const char *>
{
    size_t operator()(const char * data) const
    { return SuperFastHash(data, std::strlen(data)); }
};

template<> struct hash<char>
{
    size_t operator()(char data) const
    { return data; }
};

template<> struct hash<unsigned char>
{
    size_t operator()(unsigned char data) const
    { return data; }
};

template<> struct hash<signed char>
{
    size_t operator()(unsigned char data) const
    { return data; }
};

template<> struct hash<short>
{
    size_t operator()(short data) const
    { return data; }
};

template<> struct hash<unsigned short>
{
    size_t operator()(unsigned short data) const
    { return data; }
};

template<> struct hash<int>
{
    size_t operator()(int data) const
    { return data; }
};

template<> struct hash<unsigned int>
{
    size_t operator()(unsigned int data) const
    { return data; }
};

/**
 * WARNING: int64_t collides on 64-bit platforms with "long" types as in many
 * cases <sys/types.h> simply typedef:es int64_t to this type. Comment out
 * partial specialization here, in favor of C99 types.
 */
#if 0
template<> struct hash<long>
{
    size_t operator()(long data) const
    { return data; }
};

template<> struct hash<unsigned long>
{
    size_t operator()(unsigned long data) const
    { return data; }
};
#endif

} // \namespace types

} // \namespace tbricks

#endif // __TBRICKS__HASH__HASH_FUN__H
