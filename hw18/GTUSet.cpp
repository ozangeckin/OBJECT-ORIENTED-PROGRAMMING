#include "GTUSet.h"
using namespace std;

namespace OzanGTU
{
    template<class T>
    GTUSet<T>::GTUSet()
    {

    }
     template<class T>
    GTUSet<T>::GTUSet(int capacity,int size,int max_size)
    {
        this->capacity=capacity;
        this->size=size;
        this->max_size=max_size;
        shared_ptr<T> temp(new T[this->capacity],[](T* x){delete[] x;});
        p=temp;
    } 
    template<class T>
    int GTUSet<T>::returnSize()const
    {
        return size;
    }
    template<class T>
    int GTUSet<T>::returnMax_size()const
    {
        return max_size;
    }
    template<class T>
    void GTUSet<T>::erase(int position)
    {
        
    }
    template<class T>
    void GTUSet<T>::clear()
    {

        p.reset(new T);
        
    }
   template<class T>
     void GTUSet<T>::insert(T data){
      try{
        for(int i=0;i<returnSize();i++)
        {
            if(p.get()[i]==data)
            throw;
        }
        
            shared_ptr<T> tmp(new T[returnMax_size()]);
            for(int i=0;i<returnSize();i++)
                tmp.get()[i]=p.get()[i];
                 p=tmp;
                p.get()[returnSize()]=data;
      }catch(...){
          cout<<"Default exception"<<endl;
      }

    }
    template<class T>
    shared_ptr<T> GTUSet<T>::begin()
    {

        return shared_ptr<T>(&*p);
    }
    template<class T>
    shared_ptr<T> GTUSet<T>::end()
    {
        return shared_ptr<T>(&*p+size);
    }
    template<class T>
    bool GTUSet<T>::empty()const
    {
        if (returnSize() == 0){
            cout<<"Set is empty"<<endl;
            return true;
        }
        else{
            cout<<"Set is not empty"<<endl;
            return false;
        }   

}
}