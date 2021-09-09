#include "GTUVector.h"

using namespace std;

namespace OzanGTU
{
    template<class T>
    GTUVector<T>::GTUVector(){

    }
    template<class T>
    GTUVector<T>::GTUVector(int capacity,int size,int max_size)
    {
        this->capacity=capacity;
        this->size=size;
        this->max_size=max_size;
        shared_ptr<T> temp(new T[this->capacity],[](T* x){delete[] x;});
        pv=temp;
    }
    template<class T>
    bool GTUVector<T>::empty()const{
          if (returnSize() == 0){
            cout<<"Vector is empty"<<endl;
            return true;
        }
        else{
            cout<<"Vector is not empty"<<endl;
            return false;
        }   
    }
    template<class T>
    int GTUVector<T>::returnSize()const{
         return size;
    }
    template<class T>
    int GTUVector<T>::returnMax_size()const{
         return max_size;
    }
    template<class T>
    void GTUVector<T>::erase(int position){

    }
    template<class T>
    void GTUVector<T>::clear()
    {
         pv.reset(new T);
    }
    template<class T>
    void GTUVector<T>::insert(T data)
    {

    }
    template<class T>
    shared_ptr<T> GTUVector<T>:: begin()
    {

    }
    template<class T>
    shared_ptr<T> GTUVector<T>::end()
    {

    }
    template<class T>
    T& GTUVector<T>::operator[](const T& index){

    }
}