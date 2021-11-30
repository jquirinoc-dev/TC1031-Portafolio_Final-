#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

  #include <vector>
  #include <iostream>
  #include <fstream>
  #include <string>
  #include "ipAddress.h"

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
      void writeToNewTxt(std::string txtName, int start, int end);
      void writeFive(std::string txtName);
      void heapify(int n, int i);
      void heapSort();
      void moveDown(int i);
      void pop();
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
    while (i != 0 && data[parent(i)].getIpGrado() < data[i].getIpGrado()) {
       std::swap(data[i], data[parent(i)]);
       i = parent(i);
    }
  }

  template <class T> 
  T MaxHeap<T>::top() {
    T result;
    if (isEmpty()) {
        std::cout << "El MaxHeap está vacio" << std::endl;
        return result;
    }
    return data[0];
  }

  //O(n)
  //Toma el MaxHeap y escribe cada elemento de este en una linea de un archivo txt
  template<class T>
  void MaxHeap<T>::writeToNewTxt(std::string txtName, int start, int end){
    
    std::ofstream out(txtName);

      for (int i = start; i <= end; i++){
          std::string line;

          if (i == data.size() - 1){
              line = data[i].getIpNoPort() + "  " + std::to_string(data[i].getIpGrado());
              out << line;
          }else {
              line = data[i].getIpNoPort() + "  " + std::to_string(data[i].getIpGrado()) + "\n";
              out << line;
          }
          
      }

      out.close();
  }

  template<class T>
  void MaxHeap<T>::writeFive(std::string txtName){
      
      std::ofstream out(txtName);

      std::cout << "\nIPs with more connections:\n\n";

      out << top().getIpNoPort() + " // " + std::to_string(top().getIpGrado()) + "\n";
      std::cout << top().getIpNoPort() + " // " + std::to_string(top().getIpGrado()) << std::endl;

      for (int i = 0; i < 4; i++){
        pop();
        
        out << top().getIpNoPort() + " // " + std::to_string(top().getIpGrado()) + "\n";
        std::cout << top().getIpNoPort() + " // " + std::to_string(top().getIpGrado()) << std::endl;
        
    }

      std::cout << "\n";

      out.close();
  }

  template <class T>
  void MaxHeap<T>::heapify(int n, int i){
    
    int biggest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && data[l].getIpGrado() > data[biggest].getIpGrado()){
      biggest = l;
    }

    if (r < n && data[r].getIpGrado() > data[biggest].getIpGrado()){
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

  template <class T>
  void MaxHeap<T>::moveDown(int i) {

    int maxIndex = i;

    if (left(i) <= size && data[left(i)].getIp() > data[maxIndex].getIp()) {
      maxIndex = left(i);
    }

    if (right(i) <= size && data[right(i)].getIp() > data[maxIndex].getIp()) {
      maxIndex = right(i);
    }

    if (i != maxIndex) {

      std::swap(data[i], data[maxIndex]);
      moveDown(maxIndex);

    }
  }
  
  template <class T>
  void MaxHeap<T>::pop(){
    
    if (size < 1) {

      std::cout << "No hay ningún dato en el heap" << std::endl;
      return;

    }

    data[0] = data.back();
    data.pop_back();

    heapify(size, 0);
    size--;

    return;
    
  }
 

#endif // __MAXHEAP_H_