// Implementation of ADT Dictionary
//     data object: a bunch of contacts (phone number and name)
//     data structure: a header record in the heap with number of items and
//                    a dynamic array of Stack items using Separate Chaining
//     operations: create, destroy
//                 search the dictionary for an item given its phone number
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its phone number

#include "Dictionary.h"
#include "Stack.h"

struct DictionaryRecord
{
	int numberOfItems;
	Stack* hashPtr;
};

const int TABLESIZE = 11;

int hashFunction(const Key& theKey)
{
	return theKey.sumDigits() % TABLESIZE;
}

void print(ostream& output, Stack aStack)
{
	Item topItem;
	while (not aStack.isEmpty())
	{
		aStack.getTop(topItem);
		output << "    -> " << topItem;
		aStack.pop();
	}
}

void searchHelper(const Key& targetPhone, Item& theItem, bool& isFound, Stack aStack)
{
	isFound = false;
	
	while(not aStack.isEmpty() and !isFound)
	{
		Item aItem;
		aStack.getTop(aItem);
		if(aItem == targetPhone)
		{
			theItem = aItem;
			isFound = true;
		}
		else
			aStack.pop();
	}
}


// displays a dictionary
// pre: output has been opened if it is a file
//      rightHandSideDictionary has been assigned items
// post: output contains each item on a separate line in the format with headings.
//       for example
//       address   phone          name
//           0:
//                ->   111-1111 Frosty Snowguy
//                ->   222-2222 Blue Moon
//           1:
//                ->   111-1112 Icy Dog 
// usage: outfile << myDictionary;    
ostream& operator<< (ostream& output, const Dictionary& rightHandSideDictionary)
{
	cout << "address    phone       name  " << endl;
	for (int address = 0; address < TABLESIZE; address++)
	{
		cout << address << ":  " << endl;
		print(output, rightHandSideDictionary.dictionaryPtr -> hashPtr[address]);
	}
	
	return output;
}

// inputs items into a dictionary
// pre: input has been opened if it is a file
//      items are arranged in the following format
//      2
//      1234567 Frosty Snowguy
//      1112222 Icy Dog
// post: if there is room, 
//       all items in the input have been stored in rightHandSideDictionary
// usage: infile >> myDictionary;
istream& operator>> (istream& input, Dictionary& rightHandSideDictionary)
{
	bool isFull;
	int numberItems;
	char newLine;
	Item currentItem;
	
	input >> numberItems;
	input.get(newLine);
	
	for(int k = 0; k < numberItems; k++)
	{
		input >> currentItem;
		rightHandSideDictionary.insert(currentItem, isFull);
	}
	
	return input;
}

// creates a new dictionary
// post: Dictionary object exists but is empty
// usage: Dictionary myDictionary;
Dictionary::Dictionary()
{
	dictionaryPtr = new DictionaryRecord;
	dictionaryPtr -> hashPtr = new Stack [TABLESIZE];
	dictionaryPtr -> numberOfItems = 0;
}

// destroys a dictionary
// pre: Dictionary object exists
// post: all memory for Dictionary object has been freed
// usage: automatically done at the end of scope
Dictionary::~Dictionary()
{
	delete[] dictionaryPtr -> hashPtr;
	dictionaryPtr = nullptr;
}

// searchs for a contact with a particular phone number
// pre targetPhone has been assigned a 7-digit phone number
// post if an item with phone number the same as targetPhone is found then
//          isFound is true and theItem is that item
//       else isFound is false
// usage  contacts.search(targetPhone, anItem, isFound);
void Dictionary::search (const Key& targetPhone, Item& theItem, bool& isFound)
{
	//hash the targetPhone
	int hashAddress = hashFunction(targetPhone);
	//if hashes to empty spot => not found
	if(dictionaryPtr -> hashPtr[hashAddress].isEmpty())
		isFound = false;
	else
		searchHelper(targetPhone, theItem, isFound, dictionaryPtr -> hashPtr[hashAddress]);
	//else search stack for target phone (may not find)
	//cant follow topptr, so need to make copy and pop (need helper function)
}

// inserts a new contacts' item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the Dictionary object, isFull is false
//            and newItem is appropriately added
//       else isFull is false
// usage: myDictionary.insert(myItem, isFull);
void Dictionary::insert (const Item& newItem, bool& isFull)
{
	bool isAdded;
	int hashAddress = hashFunction(newItem);
	dictionaryPtr -> hashPtr[hashAddress].push(newItem, isAdded);
	(dictionaryPtr -> numberOfItems)++;
	isFull = not isAdded;
}

// removes the item associated with a given phone number from the dictionary
// pre: targetPhone is assigned
// post: if targetPhone is found in Dictionary object, isDone is true
//           and the associated Item object (phone and name) has been 
//           removed from the Dictionary
//       else isDone is false
// usage: myDictionary.remove(myPhone, isFound);
void Dictionary::remove (const Key& targetPhone, bool& isDone)
{
	Stack helperStack;
	Item helperItem;
	isDone = false;
	bool isAdded;
	
	int hashAddress = hashFunction(targetPhone);
	
	while(not dictionaryPtr -> hashPtr[hashAddress].isEmpty())
	{
		dictionaryPtr -> hashPtr[hashAddress].getTop(helperItem);
		if(helperItem == targetPhone)
		{
			isDone = true;
		}
		else
		{
			helperStack.push(helperItem, isAdded);
		}
		dictionaryPtr -> hashPtr[hashAddress].pop();
	}
	
	while(not helperStack.isEmpty())
	{
		helperStack.getTop(helperItem);
		dictionaryPtr -> hashPtr[hashAddress].push(helperItem, isAdded);
		helperStack.pop();
	}
}
