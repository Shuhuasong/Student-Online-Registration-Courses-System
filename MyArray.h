//05/10/2019 Shuhua Song  template + operator overloaded + Inheritance(aggregation)

#ifndef MYARRAY_H
#define MYARRAY_H

  #include <iostream>
  #include <iomanip>
  using namespace std;

//*************************Template MyArray class****************************
template <class T>
class MyArray{   // replace all the same word == command+f
public:
  MyArray();
  MyArray(int c);
  //MyArray(T c, T s);
  int getSize() const;
  int getIndex(T v) const;
  void push_back(T v);
  void pop_back();
  void erase(int index);
  void display() const;
 // The Big three
 MyArray(const MyArray<T>& a);
 ~MyArray();
 MyArray& operator =(const MyArray<T>& a);

 T& operator[](int index) const;

// dynamic array with type T

private:

  T *data;
  int capacity;
  int size;
  T* grow();
};

//#############################class MyArray<T> implementation #################
template <class T>
MyArray<T>::MyArray(): MyArray<T>(10){  }

template <class T>
MyArray<T>::MyArray(int c): capacity(c),size(0) {
  if(c<=0){
    std::cout << "The Capacity is negative" << std::endl;

  }else{
    data = new T[c];
  }
}

template <class T>
T& MyArray<T>::operator[](int index)const {
   if(index<0){
     std::cout << " The element is not exist " << std::endl;
     exit(1);
   }else{
     return data[index];
   }
}

//>=0 && < capac

  template <class T>
  int MyArray<T>::getSize() const {
      return size;
  }

  template <class T>
  int MyArray<T>::getIndex(T v) const{
    for(int i=0; i<size; i++){
      if(data[i]==v){
        return i;
      }
    }
    return -1;
  }

  template <class T>
  T* MyArray<T>::grow(){
    std::cout << "Grow function called!!" << std::endl;
    int capacity = capacity*2 +1;
    T *temp = new T[capacity];
    for(int i=0; i<size; i++){
       temp[i] = data[i];
    }
    delete [] data;
    return temp;
  }

  template <class T>
  void MyArray<T>::push_back(T v){
    if(size>=capacity){
      data = grow();
    }
    data[size] = v;
    size++;
  }

  template <class T>
  void MyArray<T>::pop_back(){
    if(size<=0){
      std::cout<< " Array is empty" << std::endl;
    }else{
      size--;
    }
  }

  template <class T>
  void MyArray<T>::erase(int index){
    if(index==-1){
      std::cout << " The element is not exist; " << std::endl;
    }else{
      for(int i=index; i<size; i++){
        data[i] = data[i+1];
      }
      size--;
    }
  }

  template <class T>
  void MyArray<T>::display() const {
    if(size>0){
      for(int i=0; i<size; i++){
        std::cout << data[i] << " ";
      }
      std::cout << std::endl;
    }
  }



  template <class T>
  MyArray<T>::MyArray(const MyArray<T>& a){
    //std::cout << " Copy Constructor Called." << std::endl;
    capacity = a.capacity;
    size = a.size;
    data = new T[a.size];
    for(int i=0; i<size; i++){
      data[i] = a.data[i];
    }
  }

  template <class T>
  MyArray<T>::~MyArray(){
      delete [] data;
  }

  template <class T>
  MyArray<T>& MyArray<T>::operator =(const MyArray<T>& a){
  //  std::cout << " Assignment overloaded function called. " << std::endl;
     if(this!=&a){
       capacity = a.capacity;
       if(size!=a.size){
         delete [] data;
         size = a.size;
         data = new T[a.size];
       }
       for(int i=0; i<size; i++){
         data[i] = a.data[i];
       }
     }
     return *this;
  }

  #endif
