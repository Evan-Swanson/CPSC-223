// testing file for class Key
// Tester.cpp

#include "Key.h"
#include "Item.h"

int main()
{
	Key akey, bkey;
	
	cout << "Enter a 7-digit phone number without spaces or dashes -> ";
	cin >> akey;
	cout << akey << endl;
   cout << akey.sumDigits() << endl;
	
	cout << "Enter a 7-digit phone number without spaces or dashes -> ";
	cin >> bkey;
	cout << bkey << endl;
	
	akey = bkey;
	cout << akey << endl;
   
   Item aitem;
   cout << "Enter a 7-digit phone number then a space then a first name space last name -> ";
   cin >> aitem;
   cout << aitem;
   
   cout << aitem.sumDigits() << endl;
	
	
	return 0;
}