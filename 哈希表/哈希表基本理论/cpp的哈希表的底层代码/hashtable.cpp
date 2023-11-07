//~~~cpp
#include "hashtable.h"

Hash::Hash()
{
    for (int i = 0; i < tableSize; ++i)
    {
        HashTable[i] = new item();
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = nullptr;
    }
}

Hash::~Hash()
{

}

int Hash::hashFunction(string key)//哈希函数，将键值转化为索引值
{
    int sum = 0;
    int index;

    for (size_t i = 0; i < key.size(); ++i)
    {
        sum += static_cast<int>(key[i]);
    }

    index = sum % tableSize;

    cout << "key[0] = " << key[0] << endl;
    cout << "key[0] = " << static_cast<int>(key[0]) << endl;
    cout << "key[1] = " << key[1] << endl;
    cout << "key[2] = " << key[2] << endl;
    cout << "sum = " << sum << endl;
    cout << "index = " << index << endl << endl;

    return index;
}

void Hash::AddItem(string name, string drink)//根据键值，来将一个新结点放进item数组中。
{
    int index = hashFunction(name);//根据哈希函数得出索引

    if (HashTable[index]->name == "empty") //判断此索引的结点元素中是否已经被赋值了
    {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else//如果此索引的结点空间已经被占用了，则将新结点放在（遍历老节点next指针后面的指针指到找到一个为空的位置）
    {
        item* p = HashTable[index];
        item* n = new item(name, drink);

        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = n;
    }
}

int Hash::NumberOfItemsInIndex(int index)//用来判断一个索引所在的单链表中，有多少个结点。（这里的单链表也可以叫	
{										//作bucket  桶）
    int count = 0;//用来计数
if (HashTable[index]->name == "empty")//如果此索引的元素为空，则返回count为0；
{
    return count;
}
else//有的话就依次遍历，
{
    count++;
    item* p = HashTable[index];
    while (p->next != nullptr)
    {
        count++;
        p = p->next;
    }
}
return count;
}

void Hash::PrintTable()//打印数组（每一个索引的第一个结点的name 和 drink）
{
    int number;
    for (int i = 0; i < tableSize; ++i)
    {
        cout << "i = " << i << ": " << endl;
        number = NumberOfItemsInIndex(i);
        cout << "index = " << i << ": " << endl;
        cout << HashTable[i]->name << ", " << HashTable[i]->drink << endl;
        cout << "# of items = " << number << endl << endl;
    }
}

void Hash::PrintItemsInIndex(int index)//打印传入索引的每一个结点元素的name和drink
{
    item* p = HashTable[index];
    if (p->name == "empty")
    {
        cout << "index = " << index << "is empty";
    }
    else
    {
        cout << "index " << index << " contains the following items \n";
        while (p != nullptr)
        {
            cout << p->name << ", " << p->drink <<endl;
            p = p->next;
        }
    }
}

void Hash::FindDrink(string name)//根据传入的键值，来寻找值
{
    int index = hashFunction(name);//根据键值找到索引
    bool FindName = false;//判断是否有此键值

    string drink;//存错元素值
    item* p = HashTable[index];
    while (p != nullptr)//遍历此索引的单链表
    {
        if (p->name == name)//如果找到有相同的键值，则记录一下drink元素值，并将FindName改为true
        {
            FindName = true;
            drink = p->drink;
        }
        p = p->next;
    }
    if (FindName)
    {
        cout << "Favorite drink " << drink << endl;
    }
    else
    {
        cout << name << "'s info was not fount in the hash table.\n";
    }
}

void Hash::RemoveItem(string name)//总之就是找出对应的索引的键值然后根据此键值在什么位置，从而来删除这个此键值的结点
{
    int index = hashFunction(name);

    item* delPtr;
    item* p1;
    item* p2;

    // case0: bucket is empty
    if (HashTable[index]->name == "empty" &&HashTable[index]->drink == "empty")
    {
        cout << name << " was not found in the hash table" << endl;
    }
    // case1: only one item contained in the bucket, and that item has matching name
    else if (HashTable[index]->name == name &&HashTable[index]->next == nullptr)
    {
        HashTable[index]->name = "empty";
        HashTable[index]->drink = "empty";
        cout << name << " was removed from the hash table" << endl;
    }
    // case 2: match is located in the first item in the bucket and there are more items in the bucket
    else if (HashTable[index]->name == name)
    {
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delPtr;
        cout << name << " was removed from the hash table" << endl;
    }
    // case 3: the bucket contains items, but first item is not a match
    else
    {
        p1 = HashTable[index]->next;
        p2 = HashTable[index];
        while (p1 != nullptr && p1->name != name)
        {
            p2 = p1;
            p1 = p1->next;
        }
        // case 3.1: no match
        if (p1 == nullptr)
        {
            cout << name << " was not found in the hash table. \n";
        }
        //case 3.2: match is found
        else
        {
            delPtr = p1;
            p1 = p1->next;
            p2->next = p1;
            delete delPtr;
            cout << name << " was removed from the hash table" << endl;
        }
    }
}


