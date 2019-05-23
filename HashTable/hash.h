#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class hashtable 
{
private:

	static const int tableSize = 10;

	struct item
	{
		string firstname;
		string secondname;
		item*next;
	};

	item*HashTable[tableSize];

	int collisions = 0;

public:

	hashtable();

	int  Hash(string key);

	void AddItem(string firstname, string secondname);

	int NumberOfItemsInIndex(int index);

	void PrintTable();

	void PrintItemsInIndex(int index);

	void FindDrink(string name);

	void RemoveItem(string name);

};