#pragma once
typedef unsigned char byte;
// MACROS
#define CONCAT(a, b) CONCAT_INNER(a, b)
#define CONCAT_INNER(a, b) a ## b

#define UNIQUE_NAME(base) CONCAT(base, __COUNTER__)

#define MAIN(func)      \
    int main() {        \
        return func();  \
    }        

#include <chrono>       
#include <iostream>     
#define TIME(func,time_unit) TIME_(func, time_unit, __COUNTER__)

#define TIME_(func, time_unit, _count) \
    auto CONCAT(start,_count) = std::chrono::high_resolution_clock::now(); \
    func(); \
    auto CONCAT(end,_count) = std::chrono::high_resolution_clock::now(); \
    auto CONCAT(duration,_count) = std::chrono::duration_cast<std::chrono::time_unit>(CONCAT(end,_count) - CONCAT(start,_count)); \
    std::cout << #func << " - " << CONCAT(duration,_count).count() << " " << #time_unit << std::endl;

#define FOR(n,s) for(unsigned int i=(s);i<(n);++i)
#define FOR(n) for(unsigned int i=0;i<(n);++i)
#define FORI(n,f) for(unsigned int i=(n)-1;i>=(f);--i)
#define FORI(n) for(unsigned int i=(n)-1;i>=0;--i)
// FUNC
#define GET(type,object,position)           \
    *(type*)(((byte*)&(object))+position)   

