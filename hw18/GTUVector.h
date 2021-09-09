#ifndef GTUVECTOR_H
#define GTUVECTOR_H

#include <iostream>
#include <memory>
#include "GTUContainer.h"

namespace OzanGTU
{
    template<class T>
    class GTUVector:public GTUContainer<T>
    {
        public:
            GTUVector();
            GTUVector(int capacity,int size, int max_size);
            bool empty()const;
            int returnSize()const;
            int returnMax_size()const;
            void erase(int position);
            void clear();
            void insert(T data);
            shared_ptr<T> begin();
            shared_ptr<T> end();
            T& operator[](const T& index);
        private:
            shared_ptr<T> pv;
            int size;
            int capacity;
            int max_size;
    };
}
#endif