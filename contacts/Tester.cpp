//testing file for class Key
//Tester.cpp

#include "Key.h"

int main()
{
	Key akey;
	Key bkey;
	Key skey("9876543");
	Key ckey("1111111");
	int sum;
	bool isEqual;
	
	//Test input and output of multiple keys
	cout << endl << "Testing key input from user and output " << endl;
	cout << "Enter a 7 digit phone number without spaces or dashes -> ";
	cin >> akey;
	cout << akey << endl;
	
	cout << "Enter a 7 digit phone number without spaces or dashes -> ";
	cin >> bkey;
	cout << bkey << endl;
	
	//Testing creating a specific phone number
	cout << endl << "Testing creating a specific number (expcted value: 9876543)" << endl;
	cout << skey << endl;
	
	//Testing multiple output
	cout << endl << "Testing multiple output (expected values first and second inputed keys)" << endl;
	cout << akey << ", " << bkey << endl;
	
	//Testing sumDigits
	cout << endl << "Testing summing the digits of a number (expected value: 42)" << endl;
	sum = skey.sumDigits();
	cout << sum << endl;
	
	//Testing operator =
	cout << endl << "Testing operator = (expected value: first inputed key)" << endl;
	bkey = akey;
	cout << bkey << endl;
	
	//Testing operator ==
	cout << endl << "Testing operator == (expected value: true)" << endl;
	if (bkey == akey)
		cout << "true" << endl;
	
	//Testing operator <
	cout << endl << "Testing operator < (expected value: true)" << endl;
	if(ckey < skey)
		cout << "true" << endl;
	if(skey < ckey)
		cout << "error" << endl;
	if (akey < bkey)
		cout << "error" << endl;
	
	
	return 0;
}