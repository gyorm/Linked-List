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
    int Count;

    LinkedList();
    bool Add(T data);
    Node<T> *Get(int itemIndex);
    bool RemoveAt(int itemIndex);
};

//###########################################

//######### Definiton of LinkedList #########

//###########################################

template <typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
    Count = 0;
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
    Count++;
    return true;
}

template <typename T>
Node<T> *LinkedList<T>::Get(int itemIndex){
    int currIndex = 0;
    Node<T> *currNode = head;

    if(Count == 0) return nullptr;
    if(itemIndex <= Count - 1){
        while(currIndex != itemIndex){
            currIndex++;
            currNode = currNode->next;
        }
        return currNode;
    }
    else return nullptr;
}

template <typename T>
bool LinkedList<T>::RemoveAt(int itemIndex){
    
}