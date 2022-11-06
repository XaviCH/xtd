#pragma once
namespace xtd {

    template<unsigned int N>
    struct arranger {

        arranger(unsigned int);
        ~arranger();

        void* get();
        void set(unsigned int,void*,unsigned int);

        void resize(unsigned int);

    private:

        void* _data;
        unsigned int _index[N];

    }




}


