#ifndef _ARDUINO_H
    #define _ARDUINO_H
    #include <Arduino.h>
#endif

#include "LinkedList.h"

LinkedList<int> *list = new LinkedList<int>();
Node<int> *curr = new Node<int>();

void setup(){
    list->Add(1993);
    list->Add(10);
    list->Add(12);
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    curr = list->head;
}

void loop(){
    Serial.println(curr->data, DEC);
    if(curr->next == nullptr) curr = list->head;
    else curr = curr->next;
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);

}
