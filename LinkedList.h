#ifndef ARDUINO_h
    #define ARDUINO_h
    #include <Arduino.h>
#endif
#ifndef LINKEDLIST_h
    #define LINKEDLIST_h

//###########################################

//######## Declaration of LinkedList ########

//################### .h ####################

template <typename T> 
class Node{
    public:
        Node();

        T data;
        Node<T> *next;
};

template <typename T>
Node<T>::Node(){
    next = nullptr;
}

template <typename T> 
class LinkedList{
    public:

    Node<T> *head; 
    Node<T> *tail;
    int Count;

    LinkedList();
    ~LinkedList();
    bool Add(T data);
    T *Get(int itemIndex);
    bool RemoveAt(int itemIndex);
    bool Clear();
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
LinkedList<T>::~LinkedList(){
    this->Clear();
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
T *LinkedList<T>::Get(int itemIndex){
    int currIndex = 0;
    Node<T> *currNode = head;

    if(itemIndex <= Count - 1){
        while(currIndex != itemIndex){
            currIndex++;
            currNode = currNode->next;
        }
        return &currNode->data;
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
        delete delNode;
        return true;
    }
    else{
        Node<T> *prevNode = this->Get(itemIndex - 1);
        delNode = prevNode->next;
        prevNode->next = delNode->next;
        delete delNode;
        return true;
    }
}

template <typename T>
bool LinkedList<T>::Clear(){
    Node<T> *currNode = head;
    Node<T> *buffNode;

    while(currNode != nullptr){
        buffNode = currNode;
        currNode = currNode->next;
        delete buffNode;
    }
    return true;
}

#endif