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
        void sort();
        void addFirst(T value);
        void addLast(T value);
        bool deleteData(T value);
        bool deleteAt(int position);
        T getData(int position);
        void updateAt(T value, T nuevo);
        void loadLogs(std::string);
        void printRange(int, int);
        void writeToNewTxt(std::string, int, int);
        void mergeSort(Node<T>**);
        void frontBackSplit(Node<T> *source, Node<T>** frontRef, Node<T>** backRef);
        Node<T> sortedMerge(Node<T>*, Node<T>*);
        void sortUsingStacks();
        void swap(Node<T>* a, Node<T>* b);
        Node<T>* lastNode(Node<T> *root);
        Node<T>* partition(Node<T> *l, Node<T> *h);
        void _quickSort(Node<T>* l, Node<T> *h);
        void recursiveQuickSort();
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
        /* std::cout << tmpLog.getAll() << std::endl; */
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

  template<class T>
  void DoubleLinkedList<T>::printRange(int start, int end){
    
    for (int i = start; i <= end; i++){
      std::cout<< this->getData(i).getAll() << std::endl;
    }

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

  /* template<class T>
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

  } */


template<class T>
void DoubleLinkedList<T>::swap ( Node<T>* a, Node<T>* b )
{ T t = a->data; a->data = b->data; b->data = t; }
 
// A utility function to find
// last node of linked list
template<class T>
Node<T>* DoubleLinkedList<T>::lastNode(Node<T> *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}
 
/* Considers last element as pivot,
places the pivot element at its
correct position in sorted array,
and places all smaller (smaller than
pivot) to left of pivot and all greater
elements to right of pivot */
template<class T>
Node<T>* DoubleLinkedList<T>::partition(Node<T> *l, Node<T> *h)
{
    // set pivot as h element
    T x = h->data;
 
    // similar to i = l-1 for array implementation
    Node<T> *i = l->prev;
 
    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Node<T> *j = l; j != h; j = j->next)
    {
        if (j->data.getDate() <= x.getDate())
        {
            // Similar to i++ for array
            i = (i == NULL)? l : i->next;
 
            swap(i, j);
        }
    }
    i = (i == NULL)? l : i->next; // Similar to i++
    swap(i, h);
    return i;
}
 
/* A recursive implementation
of quicksort for linked list */
template<class T>
void DoubleLinkedList<T>::_quickSort(Node<T>* l, Node<T> *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Node<T> *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
 
// The main function to sort a linked list.
// It mainly calls _quickSort()
template<class T>
void DoubleLinkedList<T>::recursiveQuickSort()
{
    // Find last node
    Node<T> *h = lastNode(head);
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}


//O(n log n)
template<class T>
void DoubleLinkedList<T>::iterativeQuickSort(){
    // Create an auxiliary stack

    Stack<Node<T>*> stack;

    Node<T>* l = head;
    Node<T>* h = tail;
 
    // initialize top of stack
 
    // push initial values of l and h to stack
    stack.push(l);
    stack.push(h);
 
    // Keep popping from stack while is not empty
    while (stack.getNumElements() > 0) {
        // Pop h and l
        h = stack.pop();
        l = stack.pop();
        
 
        // Set pivot element at its correct position
        // in sorted array
        Node<T>* p = partition(l, h);
 
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p->data.getDate() > l->data.getDate()) {
            /* stack[++top] = l; */
            stack.push(l);
            /* stack[++top] = p; */
            stack.push(p->prev);
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p->data.getDate() < h->data.getDate()) {
            /* stack[++top] = p + 1; */
            stack.push(p->next);
            /* stack[++top] = h; */
            stack.push(h);
        }
    }
}

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