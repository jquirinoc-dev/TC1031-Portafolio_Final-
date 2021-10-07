#ifndef _NODEQUEUE_H_
#define _NODEQUEUE_H_

  #include<iostream>

  template <class T>
  class NodeQueue { 
  public: 
      T data; 
      NodeQueue<T>* next;
      NodeQueue();
      NodeQueue(T);        
  }; 

  template<class T>
  NodeQueue<T>::NodeQueue(){
      data = 0;
      next = NULL;
  }
  template<class T>
  NodeQueue<T>::NodeQueue(T val){
      data = val;
      next = NULL;
  }

#endif // _NODEQUEUE_H_