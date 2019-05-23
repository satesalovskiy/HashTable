#include "pch.h"
#include <iostream>
#include <string>

#include "hash.h"
using namespace std;
hashtable::hashtable()
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->firstname = "empty";
		HashTable[i]->secondname = "empty";
		HashTable[i]->next=NULL;
	}
}

void hashtable::AddItem(string firstname, string secondname)
{
	
	int index = Hash(firstname);

	if (HashTable[index]->firstname == "empty")
	{
		HashTable[index]->firstname = firstname;
		HashTable[index]->secondname = secondname;
	}
	else
	{
		collisions++;
		item*Ptr = HashTable[index];
		item*n = new item;
		n->firstname = firstname;
		n->secondname = secondname;
		n->next = NULL;
		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next;
		}
		Ptr->next = n;
		//cout << "|" << n->firstname;;
		//cout <<"number of collisions: "<< collisions << endl;
	}
}
int hashtable::NumberOfItemsInIndex(int index)
{
	int count = 0;

	if (HashTable[index]->firstname == "empty")
	{
		return count;
	}
	else
	{
		count++;
		item*Ptr = HashTable[index];
		while (Ptr->next != NULL)
		{
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}
void hashtable::PrintTable()
{
	int number;
	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemsInIndex(i);
		cout << "------------------------" << endl;
		cout << "index =" << i << endl;
		cout << HashTable[i]->firstname << endl;
		cout << HashTable[i]->secondname << endl;
		cout << "number of items = " << number << endl;
		cout << "------------------------" << endl;
	}
	cout << "number of collisions: " << collisions << endl;
}
void hashtable::PrintItemsInIndex(int index)
{
	item*Ptr = HashTable[index];

	if (Ptr->firstname == "empty")
	{
		cout << "index = " << index << "is empty" << endl;
	}
	else
	{
		cout << "index = " << index << "contains following items: " << endl;

		while (Ptr != NULL)
		{
			cout << "----------------------------" << endl;
			cout << Ptr->firstname << endl;
			cout << Ptr->secondname << endl;
			cout << "----------------------------" << endl;
			Ptr = Ptr->next;
		}

	}
}
void hashtable::FindDrink(string name)
{
	int index = Hash(name);
	bool foundName = false;
	string drink;

	item*Ptr = HashTable[index];

	while (Ptr != NULL)
	{
		if (Ptr->firstname == name)
		{
			foundName = true;
			drink =Ptr->firstname + " " + Ptr->secondname;
		}
		Ptr = Ptr->next;
	}
	if (foundName == true)
	{
		cout << "Information: " << drink << endl;
	}
	else
	{
		cout << name << "'s info was not found in the HashTable" << endl;
	}
}
void hashtable::RemoveItem(string name)
{
	int index = Hash(name);

	item*delPtr;
	item*P1;
	item*P2;

	//Case 0 - bucket is empty
	if ((HashTable[index]->firstname == "empty")&&(HashTable[index]->secondname=="empty"))
	{
		cout << name << " was not found to delete" << endl;
	}
	//Case 1 - only one item is contained on the bucket and this item has matching name
	else if (HashTable[index]->firstname == name && HashTable[index]->next == NULL)
	{
		HashTable[index]->firstname == "empty";
		HashTable[index]->secondname == "empty";
		cout << name << " was deleted" << endl;
	}
	//Case 2 - match is located in the first item in the bucket but there are more items in the bucket
	else if (HashTable[index]->firstname == name)
	{
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;
		cout << name << " was deleted" << endl;
		collisions--;
	}
	//Case 3 - bucket contains items but the first item is not a match
	else
	{
		P1 = HashTable[index]->next;
		P2 = HashTable[index];
		while (P1 != NULL && P2->firstname != name)
		{
			P2 = P1;
			P1 = P1->next;
		}
		if (P1 == NULL)
		{
			cout << name << " was not found to delete" << endl;
		}
		else
		{
			delPtr = P1;
			P1 = P1->next;
			P2->next = P1;
			delete delPtr;
			cout << name << " was deleted" << endl;
			collisions--;
		}

	}
}

int hashtable::Hash(string key)
{
	int hash1 = 0;
	int index;
	cout << "New=================" << endl;
	for (int i = 0; i < key.length(); i++)
	{
		hash1 = hash1 + (int)key[i];
		cout <<"_"<< hash1;
	}
	cout << endl;
	cout << "====================" << endl;
	index = hash1 % tableSize;

	return index;
}