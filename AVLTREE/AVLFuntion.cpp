//BSTinsertAndMakeSearchPath.cpp
//Evan Swanson, Ryan Hays, Patrick Seminatore, Mason Dellutri


//Inserts a new item and assigns the search path and size
//Pre: newitem has been assigned
//Post: The item has been inserted and pathSize and path have been assigned
//Usage: BSTinsertAndMakeSearchPath(newitem, root, search);
void BSTinsertAndMakeSearchPath(const ItemType& newitem, Node*& treeptr,  SearchPath& search) throw (Exception)
{
	search.path[search.pathSize] = treeptr;			//assign current node in path
	search.pathSize = search.pathSize + 1;			//update path size
	
	if(treeptr == nullptr)
	{
		treeptr = new (nothrow) TreeNode(newitem, nullptr, nullptr);
		search.path[search.pathSize - 1] = treeptr;			//update from nullptr to new node
		if (treeptr == nullptr)
			throw Exception("No room in memory");
	}
	else if (newitem == treeptr -> item)
		throw Exception("Phone number already exists in the dictionary");
	
	else if (newitem < treeptr -> item)
		BSTinsertAndMakeSearchPath(newitem, treeptr -> leftChild, search);
	
	else
		BSTinsertAndMakeSearchPath(newitem, treeptr -> rightChild, search);

}