#ifndef _ARDUINO_H
    #define _ARDUINO_H
    #include <Arduino.h>
#endif

template <class T> 
struct Node{
    T data;
    Node<T> *next;
};

template <typename T> 
class LinkedList{
    public:

    Node<T> *head; 
    Node<T> *tail;

    LinkedList();

    bool Add(T data);
};

template <typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

template <typename T>
bool LinkedList<T>::Add(T object){
    Node<T> *newNode = new Node<T>();
    newNode->next = nullptr;
    newNode->data = object;

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }

    return true;
}