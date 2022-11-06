#pragma once
#include "../common/definitions.h"

/**
 * 
*/
struct container {

    typedef unsigned char byte;

    container(unsigned int);
    ~container();

    template<typename T> 
    inline void set(unsigned int,const T&);
    inline void set(unsigned int, void*, unsigned int);

    template<typename T> 
    inline T& get(unsigned int);
    inline void* get(unsigned int);

    template<typename T> 
    inline T& operator[](unsigned int pos) { return get<T>(pos); }
    inline void* operator[](unsigned int pos) { return get(pos); }

private:

    void* _data;
    byte* _index;
    unsigned int _sz;
};

#include "container.tpp"