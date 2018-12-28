//clientguy

#include "BinaryTree.h"
#include "Exception.h"
#include <string>
#include <fstream>
using namespace std;

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile, string filename);

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except);

void printTreeOneLabel();

void printTreeTwoLabel();

int main()
{
   BinaryTree treeOne, treeTwo;
   ifstream infile;

   OpenInputFile(infile, "Input.dat");

   try
   {	
		treeOne.makeTreeOne(infile);
   }
   
   catch (Exception except)
   {
      PrintExceptionMessage(except);
   }
	
	printTreeOneLabel();
	treeOne.prettyDisplay();
	treeOne.preorderTraverse();
	treeOne.inorderTraverse();
	treeOne.postorderTraverse();
  
   try
   {	
		treeTwo.makeTreeTwo(infile);
   }
   
   catch (Exception except)
   {
      PrintExceptionMessage(except);
   }
   
	printTreeTwoLabel();
  	treeTwo.prettyDisplay();
	treeTwo.preorderTraverse();
	treeTwo.inorderTraverse();
	treeTwo.postorderTraverse();
	
   return 0;
}

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile, string filename) 
{
   inputFile.open(filename);
   if (inputFile.fail())
   {
      cout << "File failed to open!!!!" << endl;
      exit(1);
   }
}

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except)
{
   cout << endl << endl;
   cout << except.What();
   cout << endl << endl;
}
  
void printTreeOneLabel()
{
	cout << "Full Binary Tree of height 2: " << endl << endl;
}

void printTreeTwoLabel()
{
	cout << "Complete but not full binary tree of height 3: " << endl << endl;
}

   