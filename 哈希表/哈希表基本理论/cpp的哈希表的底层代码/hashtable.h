//~~~
#ifndef HASHTABLE_H
#define HASHTABLE_H
 
#include <iostream>
#include <cstdlib>
#include <string>
 
using namespace std;
 
class Hash
{
private:
    struct item
    {
        string name;
        string drink;
        item* next;
 
        item(): name("empty"), drink("empty"), next(nullptr) {}
        item(string n, string d): name(n), drink(d), next(nullptr) {}
    };
    static const int tableSize = 10;  // 存储量可改变
    item* HashTable[tableSize];
 
public:
    int hashFunction(string key);
    Hash();
    ~Hash();
    void AddItem(string name, string drink);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    void FindDrink(string name);
    void RemoveItem(string name);
 
};
 
#endif // HASHTABLE_H


