#ifndef _ARDUINO_H
    #define _ARDUINO_H
    #include <Arduino.h>
#endif

//###########################################

//######## Declaration of LinkedList ########

//################### .h ####################

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

//################# .cpp ####################

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

    if(Count == 0 || itemIndex > Count - 1) return false;

    Node<T> *delNode;

    if(itemIndex == 0){
        delNode = head;
        head = head->next;
        free(delNode);
        return true;
    }
    else{
        Node<T> *prevNode = this->Get(itemIndex - 1);
        delNode = prevNode->next;
        prevNode->next = delNode->next;
        free(delNode);
        return true;
    }
}