#pragma once

#include <iostream>

using namespace std;

class NODE
{
public:
	int key;
	NODE * pLeft;
	NODE * pRight;
	NODE(int data);
	NODE * CreateNode(int data); // Create new node.
	void NLR(); // Preorder.
	void LNR(); // Inorder.
	void LRN(); // Postorder.
	NODE* Search(int x);
	int Height();
	friend void Insert(NODE* &pRoot, int x);
	friend void Remove(NODE* &pRoot, int x);
	friend void InsertAVL(NODE* &pRoot, int x);
	friend void RemoveAVL(NODE* &pRoot, int x);
	friend NODE* LeftRotate(NODE* pRoot);
	friend NODE* RightRotate(NODE* pRoot);
	int Balance();
	NODE* Successor();
	bool isBST();
	int countNODE();
	bool isAVL();
};