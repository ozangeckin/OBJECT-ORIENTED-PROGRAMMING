#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H

#include<iostream>
#include <memory>
using namespace std;
namespace OzanGTU
{
    template<class T>
    class GTUContainer
    {
    public:
       class GTUIterator
        {
            GTUIterator(){}
            GTUIterator(T* ptr):iter(ptr){}
            GTUIterator(const GTUIterator& oldObje):iter(oldObje.iter){}
            ~GTUIterator(){}

            GTUIterator& operator=(const GTUIterator& other)
            {
                iter=other.iter;
                return *this;
            }
            GTUIterator& operator++(){
                shared_ptr<T> r;
                iter=r.get();
                iter++;
                r=iter;
                    return r;
            }
            GTUIterator operator++(int)
            {
                GTUIterator temp_;
                temp_.iter=iter;
                iter++;
                shared_ptr<T> temp(new T[10],[](T* x){delete[] x;});
                temp=iter;
                return temp;
            }
            GTUIterator& operator--();
            GTUIterator operator--(int);
            T& operator*()const 
            {
                 return *iter; 
            }
            T* operator->()const 
            {
                 return iter; 
            }
            bool operator==(const GTUIterator& other) const 
            {
                return (iter== other.iter);
            }
            bool operator!=(const GTUIterator& other) const
            {
                return (iter != other.iter);
            }

        private:
        T* iter;
        };
    virtual bool empty() const=0;
    virtual int returnSize() const=0;
    virtual int returnMax_size() const=0;
    virtual void erase (int position) =0;
    virtual void clear()=0;
    virtual shared_ptr<T> begin()=0;
    virtual shared_ptr<T> end()=0;
    };
}
#endif