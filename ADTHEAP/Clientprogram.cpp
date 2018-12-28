// Clientprogram.cpp
// This program will test the operations in class Heap and revised class Key

#include "Exception.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "Key.h"
#include "Heap.h"

//opens an input file with a chosen name
//post if name for inputFile exists in directory, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage openInputFile(infile, filename);
void openInputFile(ifstream& inputFile);

int main()
{
   ifstream infile;
   Heap maxheap;
   Key maxKey;
   
   openInputFile(infile);
   
   infile >> maxheap;
   cout << maxheap;
   
  // maxheap.remove(maxKey);
   // cout << maxheap;
   
   return 0;
}

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void openInputFile(ifstream& inputFile) 
{
   inputFile.open("Heap.dat");
   if (inputFile.fail())
   {
      cout << "File failed to open!!!!" << endl;
      exit(1);
   }
}