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
        

      public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        int getNumElements();
        int numElements;
        void printList();
        /* void sort(); */
        void addFirst(T value);
        void addLast(T value);
        bool deleteData(T value);
        bool deleteAt(int position);
        T getData(int position);
        /* void updateAt(T value, T nuevo); */
        void loadLogs(std::string);
        void printRange(int, int);
        void writeToNewTxt(std::string, int, int);
        void swap(Node<T>* a, Node<T>* b);
        Node<T>* partition(Node<T> *l, Node<T> *h);
        void iterativeQuickSort();
        int binarySearch(dateTime key);

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


  /*template<class T>
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
  } */


  //O(1)
  template<class T>
  int DoubleLinkedList<T>::getNumElements() {
    return numElements;
  }
  
  //O(n)
  template<class T>
  void DoubleLinkedList<T>::printList() {
    Node<T> *ptr = head;
    while (ptr != NULL) {
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
    std::cout << std::endl;
  }

  //O(n)
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
  
  //O(1)
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
  
  //Mejor caso O(1)
  //Peor caso O(n) siendo n el numero de nodos de la LinkedList
  //Regresa los datos almacenados en una posicion de una lista doblemente ligada
  template<class T>
  T DoubleLinkedList<T>::getData(int position) {

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
  
  //O(n)
  //Lee un archivo txt y carga un objeto Log a una posicion de una lista ligada.
  template<class T>
  void DoubleLinkedList<T>::loadLogs(std::string txtName){
    
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
        Log tmpLog(month, day, hour, min, sec, ipa, desc, dt);
        addLast(tmpLog);

    }
}


  //O(n)
  //Toma la lista y escribe cada elemento de esta en una linea de un archivo txt
  template<class T>
  void DoubleLinkedList<T>::writeToNewTxt(std::string txtName, int start, int end){
      
      std::ofstream out(txtName);

      for (int i = start; i <= end; i++){
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

  //O(n)
  //Imprime la lista dentro de un rango especificado por dos parametros enteros que se le pasan
  template<class T>
  void DoubleLinkedList<T>::printRange(int start, int end){
    
    for (int i = start; i <= end; i++){
      std::cout<< this->getData(i).getAll() << std::endl;
    }

  }

//O(1)
//Hace un intercambio entre dos valores
template<class T>
void DoubleLinkedList<T>::swap ( Node<T>* a, Node<T>* b ){ 
  T t = a->data; 
  a->data = b->data; 
  b->data = t; 
  }
 

//O(n)
//Parte la lista
template<class T>
Node<T>* DoubleLinkedList<T>::partition(Node<T> *l, Node<T> *h){
    T x = h->data;
 
    Node<T> *i = l->prev;
 
    for (Node<T> *j = l; j != h; j = j->next)
    {
        if (j->data.getDate() <= x.getDate()){
            i = (i == NULL)? l : i->next;
            swap(i, j);
        }
    }
    i = (i == NULL)? l : i->next;
    swap(i, h);
    return i;
}
 


//O(n log n)
//Ordena la lista haciendo uso de un Stack
template<class T>
void DoubleLinkedList<T>::iterativeQuickSort(){

    Stack<Node<T>*> stack;

    Node<T>* l = head;
    Node<T>* h = tail;
 
    stack.push(l);
    stack.push(h);
 
    while (stack.getNumElements() > 0) {
        h = stack.pop();
        l = stack.pop();
        
 

        Node<T>* p = partition(l, h);
 
        if (p->data.getDate() > l->data.getDate()) {
            stack.push(l);
            stack.push(p->prev);
        }

        if (p->data.getDate() < h->data.getDate()) {
            stack.push(p->next);
            stack.push(h);
        }
    }
}

/*O(log n)
Regresa una posicion donde se encuentra una key o valor a buscar, 
en caso de no encontrarse, se regresa -1*/
template<class T>
int DoubleLinkedList<T>::binarySearch(dateTime key) {
  int low = 0;
  int high = numElements - 1;
  

  while (low <= high) {
    int m = low + (high - low) / 2;

    if (key == this->getData(m).getDate()){
        return m;
    }else if (key < this->getData(m).getDate()) {
        high = m - 1;
    }else {
        low = m + 1;
    }
      
  }
  return -1; 
}



#endif // _DOUBLELINKEDLIST_H_