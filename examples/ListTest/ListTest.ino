#ifndef _ARDUINO_H
    #define _ARDUINO_H
    #include <Arduino.h>
#endif

#include "LinkedList.h"

class City{
    public:
        City(){
        }
        City(char *Name, char *Country, int Population){
            strcpy(c_name, Name);
            strcpy(c_country, Country);
            c_pop = Population;
        }

        unsigned int c_pop;
        char c_name[30];
        char c_country[10];
};

City city1("Berlin", "GER", 3723914);
City city2("Amsterdam", "NED", 1351587);
City city3("Budapest", "HU", 2000000);

LinkedList<City> *CityList = new LinkedList<City>();
LinkedList<int> *IntList = new LinkedList<int>();

Node<City> *curr = new Node<City>();
Node<int> *intCurr = new Node<int>();

void setup(){
    CityList->Add(city1);
    CityList->Add(city2);
    CityList->Add(city3);

    IntList->Add(10);
    IntList->Add(5);
    IntList->Add(7);

    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    curr = CityList->head;
    intCurr = IntList->head;
}

void loop(){
    Serial.print("\nCityList member: (List of classes) --> ");
    Serial.print(curr->data.c_name);
    if(curr->next != nullptr) curr = curr->next;
    else curr = CityList->head;
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    Serial.print("\nIntList member: (List of integers) --> ");
    Serial.print(intCurr->data, DEC);
    if(intCurr->next != nullptr) intCurr = intCurr->next;
    else intCurr = IntList->head;
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
}
