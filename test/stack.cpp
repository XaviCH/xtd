#include <bitset>
#include <iostream>

#include "../common/definitions.h"
#include "../stack/stack.hpp"

void debug(const xtd::stack&);

int test() {
    xtd::stack stack(16);
    
    debug(stack);

    stack.push('a');
    stack.push(1);
    stack.push(-1);
    stack.push(-1.f);
    
    debug(stack);

    std::cout << stack.pop<float>() <<
    std::endl << stack.pop<int>() <<
    std::endl << stack.pop<int>() << 
    std::endl << stack.pop<char>() << std::endl;
    
    debug(stack);
    
    return 0;
}

void debug(const xtd::stack& stack) {
    void* _data = GET(void*,stack,0);
    unsigned int _stack = GET(unsigned int,stack,8);
    unsigned int _size = GET(unsigned int,stack,12);

    std::cout << "_data: ";
    FOR(_size) std::cout << std::bitset<8>(*(char*)(_data+_size-i-1)) << " ";
    std::cout << std::endl;
    std::cout << "_stack: " << _stack << std::endl;
    std::cout << "_size: " << _size << std::endl;
}

#ifndef __MAIN__
#define __MAIN__
MAIN(test)
#endif