// Specification of ADT 2-3-4 Tree Node
//    data object: a node in a 2-3-4 Tree
//        contains room for 1-3 data items (just using keys)
//        contains room for 0-4 children
//    operations: several creates, destroy, 
//       cleanUpNode,
// Built on class Key 

// This class will be used by class Two34Tree.
//     All members are public to give Two34Tree access.
// Alternatively, we could make Two34Tree a friend class
//     of this class and all members would be private.
// Programmer: dr y    Date: April 21, 2003
// Filename: Two34TreeNode.cpp


#include "Two34TreeNode.h"
using namespace std;

   // Creates an empty node
   // post: node object is empty
   // usage: Two34TreeNode node;
   Two34TreeNode::Two34TreeNode ()
   {
		for(int k = 0; k < 4; k++)
		{
			kids[k] = nullptr;
		}
		numberOfKids = 0;
		numberOfKeys = 0;
   }

   // Creates a leaf node with one item
   // pre: newKey is assigned.
   // post: newKey is in a 2-3-4 Tree Node with empty children
   // usage: root = new Two34TreeNode (newKey);
   Two34TreeNode::Two34TreeNode (const Key& newKey)
   {
	   	for(int k = 0; k < 4; k++)
		{
			kids[k] = nullptr;
		}
		numberOfKids = 0;
		keys[0] = newKey;
		numberOfKeys = 1;
   }
  
   // Creates a non-leaf 2-node
   // pre: newKey, left and right are assigned
   // post: newKey is in a 2-3-4 Tree Node (like a binary tree)
   //       with children left and right
   // usage: mroot = new Two34TreeNode (newKey, leftchild, rightchild);
   Two34TreeNode::Two34TreeNode (const Key& newKey, Two34TreeNode* left, Two34TreeNode* right)
	{
	   	for(int k = 0; k < 4; k++)
		{
			kids[k] = nullptr;
		}
		numberOfKids = 2;
		
		keys[0] = newKey;
		numberOfKeys = 1;
		
		kids[0] = left;
		kids[1] = right;
	}

   // Destroys a node
   // pre: node exists
   // post: node does not exist
   // usage: automatically called at the end of scope
   Two34TreeNode::~Two34TreeNode()
   {
	   	for(int k = 0; k < 4; k++)
		{
			kids[k] = nullptr;
		}
   }

   // Cleans up a node to become a 2-node
   // pre: the node exists with an item
   //    in leftmost position and left,right children
   //    in leftmost positions and others
   // Calls emptyIt from citem
   // post: the node's two data rightmost positions
   //    have been emptied and two rightmost children
   //    have been given away by social services.
   // usage: treep->cleanUpNode();
   void Two34TreeNode::cleanUpNode ()
   {
	   keys[1].emptyIt();
	   keys[2].emptyIt();
	   numberOfKeys = 1;
	   
	   kids[2] = nullptr;
	   kids[3] = nullptr;
	   
	   numberOfKids = 2;
   }


