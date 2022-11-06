#include <cstring>

namespace xtd {
    stack::stack(unsigned int sz = 0) {
        _data = operator new[](sz);
        _stack = 0;
        _sz = sz;
    }

    stack::~stack() {
        operator delete[](_data);
    }

    template<typename T> 
    void stack::push(const T& elem) {
        if (sizeof(T)+_stack > _sz) _resize(sizeof(T)+_stack); 
        memcpy(_data+_stack,&elem,sizeof(T));
        _stack += sizeof(T);
    }

    template<typename T> 
    T stack::pop() {
        _stack -= sizeof(T);
        return *(T*)(_data+_stack);
    }

    bool stack::empty() const { 
        return _stack;
    }

    void stack::resize(unsigned int sz) {
        _resize(sz);
    }

    void stack::_resize(unsigned int sz) {
        void* data = operator new[](sz);
        if (sz<_stack) _stack=sz;
        memcpy(data,this->_data,_stack);
        _sz = sz;
        operator delete[](_data);
        _data=data;
    }
}