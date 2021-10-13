#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

  #include <iostream>
  #include <fstream>
  #include "Node.h"
  #include "Stack.h"
  #include "dateTime.h"
  #include "Log.h"

  template <class T>
  class DoubleLinkedList {
      private:
        Node<T>* head;
        Node<T>* tail;
        int numElements;

      public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        int getNumElements();
        void printList();
        void sort();
        void addFirst(T value);
        void addLast(T value);
        bool deleteData(T value);
        bool deleteAt(int position);
        T getData(int position);
        void updateAt(T value, T nuevo);
        void loadLogs(std::string);
        void writeToNewTxt(std::string);
        void mergeSort(Node<T>**);
        void frontBackSplit(Node<T> *source, Node<T>** frontRef, Node<T>** backRef);
        Node<T> sortedMerge(Node<T>*, Node<T>*);
        void sortUsingStacks();
        /* void printListRange(int, int); */
        
      
  };

  template<class T>
  DoubleLinkedList<T>::DoubleLinkedList() {
      std::cout << "--->Creando una lista vacia " << this << std::endl;
      head = NULL;
      tail = NULL;
      numElements = 0;
  }
  
  template<class T>
  DoubleLinkedList<T>::~DoubleLinkedList() {
    std::cout << "--->Liberando memoria de la lista " << this << std::endl;
    Node<T> *p, *q;
    p = head;
    while (p != NULL) {
      q = p->next;
      delete p;
      p = q;
    }
    head = NULL;
    tail = NULL;
    numElements = 0;
  }

/*   template<class T>
  void DoubleLinkedList<T>::sort() {
    int  n = this->getNumElements();

    for (int i = 0; i < n - 1; i++) {
      int minIndex = i;
      for (int j = i + 1; j < n; j++) {
        if (this->getData(j) < this->getData(minIndex)) {
          minIndex = j;
        }
      }

      T temp = this->getData(minIndex);
      this->updateAt(this->getData(minIndex), this->getData(i));
      this->updateAt(this->getData(i), temp);
    }
    
  } */

  template<class T>
  void DoubleLinkedList<T>::updateAt(T value, T nuevo) {
    Node<T> *p;
    p = head;

    if (p != NULL && p->data == value) {
      p->data = nuevo;
    } else{
      while (p != NULL && p->data != value) {
        p = p->next;
      }

      if (p == NULL){
        std::cout << "Index out of range" << std::endl;
      } else {
        p->data = nuevo;
      }
    }
  }


  template<class T>
  int DoubleLinkedList<T>::getNumElements() {
    return numElements;
  }
  template<class T>
  void DoubleLinkedList<T>::printList() {
    Node<T> *ptr = head;
    while (ptr != NULL) {
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  template<class T>
  void DoubleLinkedList<T>::addFirst(T value) {
    Node<T> *newNode = new Node<T>(value);
    // Si la lista esta vacia 
    if (head == NULL) {
      head = newNode;
      tail = newNode;
    }
    else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    numElements++;
  }
  
  template<class T>
  void DoubleLinkedList<T>::addLast(T value) {
    // La lista esta vacia
    if (head == NULL) {
      addFirst(value);
    }
    else {
      Node<T> *newNode = new Node<T>(value);
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      numElements++;
    }    
  }
  
  template<class T>
  bool DoubleLinkedList<T>::deleteData(T value) {
    Node<T> *p, *q;
    p = head;
    q = NULL;
    // Si la lista esta vacia 
    if (p == NULL) {
      return false;
    }
    else {
      // buscar value en la lista
      while (p != NULL && p->data != value) {
        q = p;
        p = p->next;
      }
      // Si no existe value en la lista
      if (p == NULL)
        return false;
      // Si debe borrarse el primer elemento
      if (p->prev == NULL) {
        head = p->next;
        if (head != NULL)
          head->prev = NULL;
      }
      else if (p->next == NULL) { 
        // Si debe borrarse el último elemento
        q->next = NULL;
        tail = q;
      }
      else {
        // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }

  template<class T>
  bool DoubleLinkedList<T>::deleteAt(int position) {
    if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return false;
    }
    else if (position == 0) { // Si debe borrarse el primer elemento
      Node<T> *p = head;
      // Si la lista contiene solo un nodo
      if (head != NULL && head->next == NULL) {
        head = NULL;
        tail = NULL;  
      }
      else {
        head = p->next;
        head->prev = NULL;
      }
      delete p;
      numElements--;
      return true; 
    }
    else { 
      Node<T> *p = head, *q = NULL;
      int index = 0;
      while (index != position) {
        q = p;
        p = p->next;
        index++;
      }
      // Si debe borrarse el último elemento
      if (p->next == NULL) {
        q->next = NULL;
        tail = q;
      }
      else { // Cualquier otro elemento entre la lista 
        q->next = p->next;
        p->next->prev = q;
      }
      delete p;
      numElements--;
      return true;
    }
  }
  
  template<class T>
  T DoubleLinkedList<T>::getData(int position) {
    /* if (position < 0 || position >= numElements) {
      std::cout << "Indice fuera de rango" << std::endl;
      return -1;
    }
    else {
      if (position == 0)
        return head->data;
      Node<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position)
          return p->data;
        index++;
        p = p->next;
      }
      return -1;
    } */

    if (position == 0)
        return head->data;
      Node<T> *p = head;
      int index = 0;
      while (p != NULL) {
        if (index == position)
          return p->data;
        index++;
        p = p->next;
      }

      return p->data;

  }
  
  template<class T>
  void DoubleLinkedList<T>::loadLogs(std::string txtName){
    // Agregar manejo de excepciones
    
    std::string month, day, hour, min, sec, ipa, desc;
    std::ifstream in(txtName);
    while(std::getline(in, month, ' ')){
        std::getline(in, day, ' ');
        std::getline(in,hour,':');
        std::getline(in,min,':');
        std::getline(in,sec,' ');
        std::getline(in,ipa,' ');
        std::getline(in,desc);
        //std::cout << desc << std::endl;
        dateTime dt(month, stoi(day), stoi(hour), stoi(min), stoi(sec));
        Log tmpLog(month, day, hour, min, sec, ipa, desc, dt);
        addLast(tmpLog);
        std::cout << tmpLog.getAll() << std::endl;
        /* logNums++; */
    }
}

  /* template<class T>
  void DoubleLinkedList<T>::printListRange(int start, int end){

    for (int i = start; i <= end; i++){
      std::cout << getData(i).getAll() << std::endl;
    }

  } */

  template<class T>
  void DoubleLinkedList<T>::writeToNewTxt(std::string txtName){
      
      std::ofstream out(txtName);

      for (int i = 0; i < this->getNumElements(); i++){
          std::string line;

          if (i == this->getNumElements() - 1){
              line = this->getData(i).getAll();
              out << line;
          }else {
              line = this->getData(i).getAll() + "\n";
              out << line;
          }
          
      }

      out.close();
  }


  template<class T>
  void DoubleLinkedList<T>::mergeSort(Node<T> **headRef) {
    Node<T> *p = headRef;
    Node<T> *a;
    Node<T> *b;

    if (p == NULL || p->next == NULL) {
      return;
    }

    frontBackSlip(p, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    head = sortedMerge(a, b);
  }

  template<class T>
  void DoubleLinkedList<T>::frontBackSplit(Node<T> *source, Node<T>** frontRef, Node<T>** backRef){
    Node<T> *fast;
    Node<T> *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL){
      fast = fast->next;

      if (fast != NULL){
        slow = slow->next;
        fast = fast->next;

        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
      }
    }

  }

  template<class T>
  Node<T> DoubleLinkedList<T>::sortedMerge(Node<T> *a, Node<T> *b) {
    
    Node<T> *result = NULL;

    if (a == NULL){
      return b;
    } else if (b == NULL){
      return a;
    }

    if (a->data.getDate() <= b->date.getDate()){
      result = a;
      result->next = sortedMerge(a->next, b);
    } else {
      result = b;
      result->nexet = sortedMerge(a, b->next);
    }
    return result;
  }

  template<class T>
  void DoubleLinkedList<T>::sortUsingStacks(){
    
    Stack<T> input;

    for (int i = 0; i < numElements; i++){
      input.push(getData(i));
    }

    Stack<T> tmpStack = input.sortStack();

    Node<T> *p = head;

    for (int i = 0; i < numElements; i++){
      p->data = tmpStack.getTop();
      tmpStack.pop();
      p = p->next;
    }

  }

#endif // _DOUBLELINKEDLIST_H_