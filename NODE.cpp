#include "NODE.h"

NODE::NODE(int data)
{
	key = data;
	pLeft = pRight = NULL;
}

NODE* NODE::CreateNode(int data)
{
	NODE* a = new NODE(data);

	return a;
}

void NODE::NLR()
{
	if (this == NULL)
		return;
	cout << key << " ";
	pLeft->NLR();
	pRight->NLR();
}

void NODE::LNR()
{
	if (this == NULL)
		return;
	pLeft->LNR();
	cout << key << " ";
	pRight->LNR();
}

void NODE::LRN()
{
	if (this == NULL)
		return;
	pLeft->LRN();
	pRight->LRN();
	cout << key << " ";
}

NODE* NODE::Search(int x)
{
	if (this == NULL)
		return NULL;
	if (key == x)
		return this;
	if (key < x)
		return pRight->Search(x);
	if (key > x)
		return pLeft->Search(x);
}

int NODE::Height()
{
	if (this == NULL)
		return 0;
	return 1 + ((pLeft->Height() > pRight->Height()) ? pLeft->Height() : pRight->Height());
}

void Insert(NODE* &pRoot, int x)
{
	if (pRoot == NULL)
	{
		pRoot = new NODE(x);
		return;
	}		
	if (pRoot->key < x)
		Insert(pRoot->pRight, x);
	else if (pRoot->key > x)
		Insert(pRoot->pLeft, x);
	else
		return;
}

NODE* NODE::Successor()
{
	if (pLeft == NULL)
		return this;
	return pLeft->Successor();
}

void Remove(NODE* &pRoot, int x)
{
	if (pRoot == NULL)
	{
		return;
	}
	if (pRoot->key < x)
		Remove(pRoot->pRight, x);
	else if (pRoot->key > x)
		Remove(pRoot->pLeft, x);
	else 
	{
		if (pRoot->pLeft == NULL && pRoot->pRight == NULL)
		{
			delete pRoot;
			pRoot = NULL;
			return;
		}
		else if (pRoot->pLeft == NULL)
		{
			NODE* temp = pRoot;
			pRoot = pRoot->pRight;
			delete temp;
			return;
		}
		else if (pRoot->pRight == NULL)
		{
			NODE* temp = pRoot;
			pRoot = pRoot->pLeft;
			delete temp;
			return;
		}
		else
		{
			NODE* temp = pRoot->pRight->Successor();
			pRoot->key = temp->key;
			Remove(pRoot->pRight, temp->key);
			return;
		}
	}
}

bool NODE::isBST()
{
	static NODE* prev = NULL;

	if (this)
	{
		if (!pLeft->isBST())
			return false;

		if (prev != NULL && key <= prev->key)
			return false;

		prev = this;

		return pRight->isBST();
	}

	return true;
}

int NODE::countNODE()
{
	if (this == NULL)
		return 0;

	return 1 + pLeft->countNODE() + pRight->countNODE();
}

bool NODE::isAVL()
{
	if (this == NULL)
		return true;

	if (abs(this->pLeft->Height() - this->pRight->Height()) <= 1 && this->pLeft->isAVL() && this->pRight->isAVL())
		return true;
	
	return false;
}

NODE* LeftRotate(NODE* pRoot)
{
	NODE* temp = pRoot->pRight;
	NODE* T2 = temp->pLeft;

	temp->pLeft = pRoot;
	pRoot->pRight = T2;

	return temp;
}

NODE* RightRotate(NODE* pRoot)
{
	NODE* temp = pRoot->pLeft;
	NODE* T3 = temp->pRight;

	temp->pRight = pRoot;
	pRoot->pLeft = T3;

	return temp;
}

int NODE::Balance()
{
	if (!this)
		return 0;

	return this->pLeft->Height() - this->pRight->Height();
}

void InsertAVL(NODE* &pRoot, int x)
{
	if (pRoot == NULL)
	{
		pRoot = new NODE(x);
		return;
	}
	if (x > pRoot->key)
		InsertAVL(pRoot->pRight, x);
	else if (x < pRoot->key)
		InsertAVL(pRoot->pLeft, x);
	else
		return;

	int balance = pRoot->Balance();

	if (balance > 1 && x < pRoot->pLeft->key)
	{
		pRoot = RightRotate(pRoot);
		return;
	}
		

	if (balance < -1 && x > pRoot->pRight->key)
	{
		pRoot = LeftRotate(pRoot);
		return;
	}

	if (balance > 1 && x > pRoot->pLeft->key)
	{
		pRoot->pLeft = LeftRotate(pRoot->pLeft);
		pRoot = RightRotate(pRoot);
		return;
	}

	if (balance < -1 && x < pRoot->pRight->key)
	{
		pRoot->pRight = RightRotate(pRoot->pRight);
		pRoot = LeftRotate(pRoot);
		return;
	}

	return;
}

void RemoveAVL(NODE* &pRoot, int x)
{
	if (pRoot == NULL)
		return;
	else if (pRoot->key < x)
		RemoveAVL(pRoot->pRight, x);
	else if (pRoot->key > x)
		RemoveAVL(pRoot->pLeft, x);
	else
	{
		if (pRoot->pLeft == NULL && pRoot->pRight == NULL)
		{
			delete pRoot;
			pRoot = NULL;
		}

		else if (pRoot->pRight == NULL)
		{
			NODE* temp = pRoot;
			pRoot = pRoot->pLeft;
			delete temp;
		}

		else if (pRoot->pLeft == NULL)
		{
			NODE* temp = pRoot;
			pRoot = pRoot->pRight;
			delete temp;
		}

		else
		{
			NODE* temp = pRoot->pRight->Successor();
			pRoot->key = temp->key;
			RemoveAVL(pRoot->pRight, temp->key);
		}
	}

	if (pRoot == NULL)
		return;

	int balance = pRoot->Balance();

	if (balance > 1 && pRoot->pLeft->Balance() >= 0)
	{
		pRoot = RightRotate(pRoot);
		return;
	}

	if (balance < -1 && pRoot->pRight->Balance() <= 0)
	{
		pRoot = LeftRotate(pRoot);
		return;
	}

	if (balance > 1 && pRoot->pLeft->Balance() < 0)
	{
		pRoot->pLeft = LeftRotate(pRoot->pLeft);
		return;
	}

	if (balance < -1 && pRoot->pRight->Balance() > 0)
	{
		pRoot->pRight = RightRotate(pRoot->pRight);
		return;
	}

	return;
}