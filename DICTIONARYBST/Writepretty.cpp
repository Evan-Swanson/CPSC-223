void writePretty (TreeNode* treep, int level)
{
	if (treep != nullptr)
    {
        writePretty(treep -> rightChild, level + 1);
        if (treep -> rightChild != nullptr)
        {
            for (int i = 0; i < level; i++)
            {
                cout << "                    ";
            }
            cout << "/" << endl;
        }
        if (level == 1)
        {
            cout << "root -> ";
        }
        else
        {
            for (int i = 0; i < level - 1; i++)
            {
                cout << "                     ";
            }
        }
        cout << treep -> item;
        if (treep -> leftChild != nullptr)
        {
            for (int i = 0; i < level; i++)
            {
                cout << "                    ";
            }
            cout << "\\" << endl;
            writePretty(treep -> leftChild, level + 1);
        }
    }
}
