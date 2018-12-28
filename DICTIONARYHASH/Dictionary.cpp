//Dictionary.cpp 
//Specification of ADT Dictionary
//     data object: a bunch of contacts (phone number and name)
//     operations: create, destroy
//                 search the dictionary for an item given its phone number
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its phone number

#include "Dictionary.h"
#include "Item.h"

const int TABLESIZE = 11;

struct DictionaryRecord
{
	int numberOfItems;
	Item* hashPtr;
};

//hashes a phone number to an array index
//pre: theKey is assigned
//post: returns an index for the phone number
//usage: hashFunction(myKey)
int hashFunction(const Key& theKey)
{
	return theKey.sumDigits() % TABLESIZE;
}

// displays a dictionary
// pre: output has been opened if it is a file
//      rightHandSideDictionary has been assigned items
// post: output contains each item on a separate line in the format with headings.
//       for example
//       address  phone       name
//       	0	  123-4567    Frosty Snowguy
//       	1	  111-2222    Icy Dog 
// usage: outfile << myDictionary;    
ostream& operator<< (ostream& output, const Dictionary& rightHandSideDictionary)
{
	output << "Address    phone     name" << endl;
	
	Item nextItem;
	
	for(int k = 0; k < TABLESIZE; k++)
	{
		nextItem = rightHandSideDictionary.dictionaryPtr -> hashPtr[k];
		if(k < 10)
			output << k << "       " << nextItem;
		else
			output << k << "      " << nextItem;
	}
	output << endl;
	return output;
}

// inputs items into a dictionary
// pre: input has been opened if it is a file
//      items are arranged in the following format
//		2
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
	dictionaryPtr -> numberOfItems = 0;
	dictionaryPtr -> hashPtr = new Item [TABLESIZE];
}

// destroys a dictionary
// pre: Dictionary object exists
// post: all memory for Dictionary object has been freed
// usage: automatically done at the end of scope
Dictionary::~Dictionary()
{
	delete[] dictionaryPtr -> hashPtr;
}

// searchs for a contact with a particular phone number
// pre targetPhone has been assigned a 7-digit phone number
// post if an item with phone number the same as targetPhone is found then
//          isFound is true and theItem is that item and theIndex is the index of that item
//       else isFound is false
// usage  contacts.search(targetPhone, anItem, isFound, theIndex);
void Dictionary::search (const Key& targetPhone, Item& theItem, bool& isFound, int& theIndex)
{
	int index, hashLocation;
	bool isNotHere = false;
	
	hashLocation = hashFunction(targetPhone);
	index = hashLocation;
	isFound = false;
	
	for(index; !isFound && !isNotHere; index++)
	{
		if(dictionaryPtr -> hashPtr[index].isEmpty())
		{
			isNotHere = true;
		}
		
		else if(dictionaryPtr -> hashPtr[index] == targetPhone)
		{
			isFound = true;
			theItem = dictionaryPtr -> hashPtr[index];
		}
		
		else if(index == hashLocation - 1)
		{
			isNotHere = true;
		}
	}
	 
	 theIndex = index - 1;
	
}

// inserts a new contacts' item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the Dictionary object, isFull is false
//            and newItem is appropriately added
//       else isFull is false
// usage: myDictionary.insert(myItem, isFull);
void Dictionary::insert (const Item& newItem, bool& isFull)
{	
	isFull = (dictionaryPtr -> numberOfItems == TABLESIZE);
	if(not isFull)
	{	
		int hashLocation, index;
		
		hashLocation = hashFunction(newItem);
		index = hashLocation;
		
		while(not (dictionaryPtr -> hashPtr[index].isEmpty() or dictionaryPtr -> hashPtr[index].hasBeenUsed()))
		{
			index = (index + 1) % TABLESIZE;
		}
		
		dictionaryPtr -> hashPtr[index] = newItem;
		dictionaryPtr -> numberOfItems = dictionaryPtr -> numberOfItems + 1;
	}
	
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
	bool isFound = false;
	int index;
	Item theItem;
	
	search(targetPhone, theItem, isFound, index);
	if(isFound)
	{
		dictionaryPtr -> hashPtr[index].setUsed();
	}
	
	dictionaryPtr -> numberOfItems = dictionaryPtr -> numberOfItems - 1;
}

