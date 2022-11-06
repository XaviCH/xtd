#pragma once
namespace xtd {
    /**
     * Stack works like a memmory stack. Push types on a consecutive memory line.
     * All memory is copied, not moved or addressed at the stack. So be carefull with pointer, 
     * it just copy pointer address, not it's value.
     * 
     * 
    */
    struct stack {

        stack(unsigned int);
        ~stack();

        template<typename T> 
        inline void push(const T&);

        template<typename T> 
        inline T pop();

        inline bool empty() const;

        void resize(unsigned int);

    private:

        inline void _resize(unsigned int);

        void* _data;
        unsigned int _stack;
        unsigned int _sz;

    };
}
#include "stack.tpp"