#ifndef _STACK_NODE_H_
#define _STACK_NODE_H_

  #include<iostream>

  template <class T>
  class StackNode { 
  public: 
      T data; 
      StackNode<T>* next;
      StackNode();
      StackNode(T);        
  }; 

  template<class T>
  StackNode<T>::StackNode(){
      data = 0;
      next = NULL;
  }
  template<class T>
  StackNode<T>::StackNode(T val){
      data = val;
      next = NULL;
  }

#endif // _STACK_NODE_H_