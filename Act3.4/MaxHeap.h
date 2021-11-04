#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

  #include <vector>
  #include <iostream>
  #include <fstream>
  #include "dateTime.h"
  #include "ipAddress.h"
  #include "Log.h"

  template<class T>
  class MaxHeap {
    private:
      // contiene los elementos del heap
      std::vector<T> data; 
      // capacidad maxima del heap
      int maxSize;
      // tamaño actual del heap   
      int size;   

      int parent(int i);
      int left(int i);
      int right(int i);

    public:
      MaxHeap(int capacity);
      ~MaxHeap();
      bool isEmpty();
      int getSize();
      int getCapacity();
      void printMaxHeap();
      void push(T key);
      void loadLogs(std::string txtName);
      void writeToNewTxt(std::string txtName, int start, int end);
      void heapify(int n, int i);
      void heapSort();
      T top();


  };

  template <class T> 
  MaxHeap<T>::MaxHeap(int capacity) {
      std::cout << "--->Creando un MaxHeap: " <<  this << std::endl;
      size = 0;
      maxSize = capacity;
      data.resize(maxSize);
  }

  template <class T> 
  MaxHeap<T>::~MaxHeap() {
      std::cout << "--->Liberando memoria del MaxHeap: " <<  this << std::endl;
      data.clear();
  }
  
  template <class T> 
  bool MaxHeap<T>::isEmpty() {
    return (size <= 0);
  }

  template <class T> 
  int MaxHeap<T>::getSize() {
    return size;
  }

  template <class T> 
  int MaxHeap<T>::getCapacity() {
    return maxSize;
  }

  template <class T> 
  void MaxHeap<T>::printMaxHeap() {
    for (int i=0; i < size; i++)
      std::cout << data[i].getAll() << std::endl;
  }

  template <class T> 
  int MaxHeap<T>::parent(int i) {
    return (i-1)/2; 
  }
  
  template <class T> 
  int MaxHeap<T>::left(int i) {
    return (2*i + 1); 
  }

  template <class T> 
  int MaxHeap<T>::right(int i) {
    return (2*i + 2);
  }

  template <class T> 
  void MaxHeap<T>::push(T key) {
    if (size == maxSize) {
        std::cout << "Overflow: no se puede insertar la llave: " << std::endl;
        return;
    }
    // Insertamos la nueva llave al final del vector
    int i = size;
    data[i] = key;
    size++;
    // Reparar las propiedades del max heap si son violadas
    while (i != 0 && data[parent(i)].getIp() < data[i].getIp()) {
       std::swap(data[i], data[parent(i)]);
       i = parent(i);
    }
  }

  template <class T> 
  T MaxHeap<T>::top() {
    T result = -1;
    if (isEmpty()) {
        std::cout << "El MaxHeap está vacio" << std::endl;
        return result;
    }
    return data[0];
  }

  template <class T>
  void MaxHeap<T>::loadLogs(std::string txtName){
    
    std::string month, day, hour, min, sec, ipa, desc;
    std::ifstream in(txtName);

    while(std::getline(in, month, ' ')){
        std::getline(in, day, ' ');
        std::getline(in,hour,':');
        std::getline(in,min,':');
        std::getline(in,sec,' ');
        std::getline(in,ipa,' ');
        std::getline(in,desc);

        dateTime dt(month, stoi(day), stoi(hour), stoi(min), stoi(sec));
        ipAddress ia(ipa);

        Log tmpLog(month, day, hour, min, sec, ipa, desc, dt, ia);

        /* std::cout << tmpLog.getAll() << std::endl; */

        push(tmpLog);

    }
  in.close();
}

  //O(n)
  //Toma el MaxHeap y escribe cada elemento de este en una linea de un archivo txt
  template<class T>
  void MaxHeap<T>::writeToNewTxt(std::string txtName, int start, int end){
      
      std::ofstream out(txtName);

      for (int i = start; i <= end; i++){
          std::string line;

          if (i == data.size() - 1){
              line = data[i].getAll();
              out << line;
          }else {
              line = data[i].getAll() + "\n";
              out << line;
          }
          
      }

      out.close();
  }

  template <class T>
  void MaxHeap<T>::heapify(int n, int i){
    
    int biggest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && data[l].getIp() > data[biggest].getIp()){
      biggest = l;
    }

    if (r < n && data[r].getIp() > data[biggest].getIp()){
      biggest = r;
    }

    if (biggest != i){
      std::swap(data[i], data[biggest]);
      heapify(n, biggest);
    }
  }


  template <class T>
  void MaxHeap<T>::heapSort(){

    int n = size;

    for (int i = (n / 2) - 1; i >= 0; i--){
      heapify(n, i);
    }

    for (int i = n - 1; i > 0; i--){
      std::swap(data[0], data[i]);
      heapify(i, 0);
    }
  }


#endif // __MAXHEAP_H_