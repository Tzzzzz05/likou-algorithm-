//~~~cpp
#include "hashtable.h"
 
int main()
{
    Hash hash;
    string name1 = " ";
    string name2 = " ";
    hash.PrintTable();
 
    hash.AddItem("Paul", "Locha");
    hash.AddItem("Kim", "Iced Mocha");
    hash.AddItem("Anni", "Strawberry Smoothy");
    hash.AddItem("Sara", "Passion Tea");
    hash.AddItem("Mike", "Tea");
    hash.AddItem("steve", "Apple cider");
    hash.AddItem("Sill", "Root beer");
    hash.AddItem("Bill", "Lochs");
    hash.AddItem("Susan", "Cola");
    hash.AddItem("Joe", "Green Tea");
 
    hash.PrintTable();
    hash.PrintItemsInIndex(0);
 
    while (name1 != "exit")
    {
        cout << "search for: ";
        cin >> name1;
        if (name1 != "exit")
        {
            hash.FindDrink(name1);
        }
    }
 
    cout << endl;
 
    while (name2 != "exit")
    {
        cout << "Remove: ";
        cin >> name2;
        if (name2 != "exit")
        {
            hash.RemoveItem(name2);
        }
    }
 
    hash.PrintTable();
    hash.PrintItemsInIndex(0);
 
    return 0;
}


