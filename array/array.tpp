#include "array.h"

#define UPDATE if (_filter) update()

template<typename T>
array<T>::array(uint sz = 0) {
    _data = (T*) operator new(sizeof(T)*sz);
    _sz=0;
    _alloc=sz;
    _filter = nullptr;
}

template<typename T>
array<T>::~array() {
    FOR(i,_size) _data[i].~A();
    operator delete[](_data);
    if (_filter) operator::delete[](_filter);
}

template<typename T>
array<T>& filter(bool(*func)(const T&)) const {
    bool* filter = (bool*) operator::new(_sz);
    for(uint i=0; i<_sz; ++i) 
        if (this->_filter) {
            if (this->_filter[i])  filter=func(_data[i]);
            else filter=false;
        }
    return array<T>::array(data, _sz, filter);
}

template<typename T>
T& get(uint i) {
    UPDATE;
    return _data[i];
}

template<typename T>
T& set(uint i, T& elem) {
    UPDATE;
    std::move(elem, _data);
}