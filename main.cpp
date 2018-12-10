#include "NODE.h"

int main()
{
	/*NODE* pRoot = new NODE(7);
	Insert(pRoot, 3);
	Insert(pRoot, 2);
	Insert(pRoot, 4);
	Insert(pRoot, 9);
	Insert(pRoot, 8);
	Insert(pRoot, 12);
	Insert(pRoot, 10);

	pRoot->NLR();
	cout << endl;
	pRoot->LNR();
	cout << endl;
	pRoot->LRN();
	cout << endl;

	cout << "Nodes: " << pRoot->countNODE() << endl;

	Remove(pRoot, 7);
	NODE* k = pRoot->Search(7);
	if (k)
		cout << k->key << endl;
	else
		cout << "Not found!" << endl;

	pRoot->NLR();
	cout << endl;
	pRoot->LNR();
	cout << endl;
	pRoot->LRN();
	cout << endl;

	cout << "Height of Tree: " << pRoot->Height() << endl;

	if (pRoot->isBST())
		cout << "This is BST" << endl;
	else
		cout << "This is not BST" << endl;

	cout << "Nodes: " << pRoot->countNODE() << endl;*/

	NODE *pRoot = NULL;
	InsertAVL(pRoot, 9);
	InsertAVL(pRoot, 5);
	InsertAVL(pRoot, 10);
	InsertAVL(pRoot, 0);
	InsertAVL(pRoot, 6);
	InsertAVL(pRoot, 11);
	InsertAVL(pRoot, -1);
	InsertAVL(pRoot, 1);
	InsertAVL(pRoot, 2);

	pRoot->NLR();
	cout << endl;

	RemoveAVL(pRoot, 10);

	pRoot->NLR();
	cout << endl;

	if (pRoot->isAVL())
		cout << "This is AVL tree" << endl;
	else
		cout << "This is not AVL tree" << endl;

	system("pause");
	return 0;
}