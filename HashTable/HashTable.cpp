
#include "pch.h"
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;
const char * ar[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S",
		"T", "U", "V", "W", "X", "Y", "Z"};
int main()
{
	int N;
	hashtable Hashy;
	/*cout << "The number of new items: " << endl;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s="";
		string ss = "";
		for (int j = 1; j <rand()%26 ; j++)
		{
			s += ar[rand() % (sizeof ar / sizeof(char*))];			
		}
		for (int j = 1; j < rand() % 26; j++)
		{
			ss += ar[rand() % (sizeof ar / sizeof(char*))];
		}
		Hashy.AddItem(s, ss);
	}*/
	Hashy.AddItem("S", "T456");
	Hashy.AddItem("K", "G123");
	Hashy.AddItem("IF", "L867");
	Hashy.AddItem("IP", "B0m8");
	Hashy.PrintTable();
	cout << "Display index: " << endl;
	int p;
	cin >> p;
	Hashy.PrintItemsInIndex(p);	
	string name1;
	while (name1 != "exit")
	{
		cout << "What name to search?: " << endl;
		cin >> name1;
		if(name1!="exit")
		    Hashy.FindDrink(name1);
	}
	cout << "What to remove?: " << endl;
	string p2;
	cin >> p2;
	Hashy.RemoveItem(p2);
	Hashy.PrintTable();
	cout << "What name to search?: " << endl;
	cin >> name1;
	if (name1 != "exit")
		Hashy.FindDrink(name1);
	_getwch();
	return 0;
}
