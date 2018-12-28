// inserting items (integers) into a dictionary (hash table)
// Evan Swanson
// Hashprogram.cpp

#include <iostream>

const int MAXSIZE = 7;

using namespace std;

int hashFunction(int item);
void print(int hashTable[]);
void input(int hashTable[]);
void initializeTable(int hashTable[]);

int main()
{	
	int hashTable[MAXSIZE];
	initializeTable(hashTable);
	input(hashTable);
	print(hashTable);
	
	return 0;
}

int hashFunction(int item)
{
	return item % MAXSIZE;
}

void print(int hashTable[])
{
	cout << "Index  Item" << endl; 
	for (int k = 0; k < MAXSIZE; k++)
	{
		cout << k << "   :   " << hashTable[k] << endl;
	}
}

void input(int hashTable[])
{
	int item;
	for (int k = 0; k < 3; k++)
	{
		cout << "Enter an integer -> ";
		cin >> item;
		hashTable[hashFunction(item)] = item;
	}
}

void initializeTable(int hashTable[])
{
	for (int k = 0; k < MAXSIZE; k++)
	{
		hashTable[k] = -1;
	}
	
}
