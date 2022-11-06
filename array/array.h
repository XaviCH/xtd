#include "../common/definitions"

template<class T>
struct array {

private:

    T* _data;
    uint _sz; // constructed allocated memory 
    uint _alloc; // allocated memory
    bool* _filter; // lazy arrays only

    // lazy array
    array(T*,uint,uint,bool*);
    inline void update();

public:

    array(uint); // new array
    ~array();

    inline T& get(uint);
    // T& first(bool(*)(const T&)) const;
    // T& last(bool(*)(const T&)) const;
    // inline void set(uint,T&);
    // inline void set(uint,const T&);
    // inline void set(uint,T&&);
    // void resize(uint);
    // void for_each(void*)(T&);
    // template<class R>
    // array<R>& for_each(R(*)(T&));
    // void order();
    // void order(bool(*)(const T&,const T&));
    lazy_array<T>& filter(bool(*)(const T&)) const;
    array<T>&& filter(bool(*)(const T&)) const;
    // template<class R>
    // array<R>& map(R(*)(const T&)) const;
    // array<T>& sort() const;
    // array<T>& sort(bool(*)(const T&, const T&)) const;
    

}

/*
utils::array a1 = [...]
utils::array<bool> a_mult_3_mult_5 = a1.filter([](int x] -> bool {return x%3;}).filter(bool[int x%5]->).map<bool>(bool[intx ]);
utils::array<bool> a_value = a1.map(Person::get_name)


a.filter([](T e) -> { return e.inizilixed(); })

for 
// array = list.fliter.filter.filter