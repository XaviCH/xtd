#include "container.h"
#include <cstring>

container::container(unsigned int sz) {
    _data = operator new(sz*2);
    _index = (byte*) operator new(sz);
    _sz = sz;
}

container::~container() {
    operator delete[](_data);
    operator delete[](_index);
}

void container::set(unsigned int pos, void* pointer, unsigned int sz) {
    byte* upointer = (byte*)_data+_index[pos];
    memcpy(upointer,pointer,sz);
    if(pos+1<_sz) _index[pos+1]=_index[pos]+sz;
}

template<typename T> 
void container::set(unsigned int pos,const T& elem) {
    byte* upointer = (byte*)_data+_index[pos];
    memcpy(upointer,&elem,sizeof(elem));
    if(pos+1<_sz) _index[pos+1]=_index[pos]+sizeof(elem);
}

void* container::get(unsigned int pos) {
    return _data+_index[pos];
}

template<typename T> 
T& container::get(unsigned int pos) {
    return *((T*)(_data+_index[pos]));
}
