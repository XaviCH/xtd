#include <bitset>
#include <iostream>
#include <map>
#include <chrono>

#include "../common/definitions.h"
#include "../dictionary/dictionary.hpp"
 
void debug(const xtd::dictionary&);

void dict_pointer_get_and_assign() {
    xtd::dictionary dict;
    FOR(1000000) dict["alpha"] = i;
}

void map_get_and_assign() {
    std::map<std::string, int> map;
    FOR(1000000) map["alpha"] = i;
}

void dict_set_and_assign() {
    xtd::dictionary dict;
    FOR(4) dict["alpha"+i] = i;
}

void map_set_and_assign() {
    std::map<std::string, int> map;
    FOR(10000) map["alpha"+i] = i;
}

int test() {
    TIME(dict_pointer_get_and_assign,milliseconds)
    TIME(map_get_and_assign,milliseconds)
    TIME(dict_set_and_assign,milliseconds)
    TIME(map_set_and_assign,milliseconds)
    xtd::dictionary dict;
    dict["alpha"] = 1;
    std::cout << 1+dict["alpha"] << std::endl;
    return 0;
}

// DEBUG IMPLEMENTATIONS
struct heap_d { char* key; void* value; heap_d* left; heap_d* right; };

void debug(const xtd::dictionary& dict) {
    heap_d* _heaps = GET(heap_d*,dict,0);

    using namespace std;
}

#ifndef __MAIN__
#define __MAIN__
MAIN(test)
#endif