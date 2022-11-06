#define HASH_SIZE_DICT 16 

namespace xtd {
    /**
     * Dictionary is a class that store values with an asocieted string key.
    */
    struct dictionary {
    
    private:

        struct dictionary_pointer {
        private:
            dictionary* _dict;
            char* _key;

        public:
            dictionary_pointer(dictionary*,const char* key);
            ~dictionary_pointer();
            
            template<typename T>
            void operator=(const T&);

            dictionary_pointer operator[](const char* key);

            template<typename T>
            operator T() const;

        };

        struct heap {
            char* key;
            void* value;
            
            heap* left;
            heap* right;

            heap();
            ~heap();

            template<typename T>
            void set(const char*,const T&);

            heap* get(const char*);

            template<typename T>
            static inline void _set(heap*,const char*,const T&);

        };

    public:

        template <typename T>
        T& get(const char*);


        template <typename T>
        void set(const char*,const T&);

        dictionary_pointer operator[](const char* key);

    private:

        void* get(const char*);
        
        heap _heaps[HASH_SIZE_DICT];
        inline unsigned int hash_key(const char*);

    };
}
#include "dictionary.tpp"