#include <string.h>

namespace xtd {

    dictionary::dictionary_pointer::dictionary_pointer
        (dictionary* dict, const char* key) 
    {
        _dict = dict;
        unsigned int len = strlen(key)+1; 
        _key = (char*) operator new[](len);
        memcpy(_key, key, len);
    }

    dictionary::dictionary_pointer::~dictionary_pointer() {
        operator delete[](_key);
    }

    template<typename T>
    void dictionary::dictionary_pointer::operator=(const T& elem) {
        _dict->set(_key,elem);
    }

    dictionary::dictionary_pointer dictionary::dictionary_pointer::operator[](const char* key) {
        return _dict->get<dictionary>(_key)[key];
    }

    template<typename T>
    dictionary::dictionary_pointer::operator T() const {
        return *(T*)_dict->get(_key);
    }

    dictionary::heap::heap() {
        key = nullptr;
        value = nullptr;
        left = nullptr;
        right = nullptr;
    }

    dictionary::heap::~heap() {
        if (key) operator delete[](key);
        if (value) operator delete[](value);
        if (left) delete[](left);
        if (right) delete[](right);
    }

    template<typename T>
    void dictionary::heap::_set(dictionary::heap* heap,const char* key,const T& value) {
        unsigned int len = strlen(key)+1; 
        heap->key = (char*) operator new[](len);
        memcpy(heap->key, key, len);
        heap->value = operator new[](sizeof(T));
        memcpy(heap->value,&value,sizeof(value));
    }

    template<typename T>
    void dictionary::heap::set(const char* key,const T& value) {
        if (!this->key) { 
            _set(this,key,value);
            return;
        }
        
        dictionary::heap* heap = this;
        dictionary::heap* above;
        int cmp;
        do {
            above = heap;
            cmp = strcmp(this->key,key);
            if (!cmp) break;
            if (cmp>0) heap = heap->right;
            else heap = heap->left;
        } while(heap);

        if (!heap) {
            heap = new dictionary::heap();
            if (cmp>0) above->right = heap;
            else above->left = heap;
            _set(heap,key,value);
        } else {
            operator delete[](this->value);
            this->value = operator new[](sizeof(T));
            memcpy(this->value,&value,sizeof(value));
        }
        
    }

    dictionary::heap* dictionary::heap::get(const char* key) {
        dictionary::heap* heap = this;
        do {
            int cmp = strcmp(this->key,key);
            if (!cmp) break;
            if (cmp>0) heap = heap->right;
            else heap = heap->left;
        } while(heap);
        return heap;
    }

    template <typename T>
    void dictionary::set(const char* key, const T& elem) {
        unsigned char hash = hash_key(key);
        _heaps[hash].set(key,elem);
    }

    template <typename T>
    T& dictionary::get(const char* key) {
        unsigned char hash = hash_key(key);
        return *(T*)_heaps[hash].get(key)->value;
    }

    void* dictionary::get(const char* key) {
        unsigned char hash = hash_key(key);
        return _heaps[hash].get(key)->value;
    }

    unsigned int dictionary::hash_key(const char* key) {
        return (*key)%HASH_SIZE_DICT;
    }

    dictionary::dictionary_pointer dictionary::operator[](const char* key) {
        return dictionary_pointer(this,key);
    }

}