#include <iostream>
using namespace std;

#define STACK_MAX_SIZE 30
#define QUEUE_MAX_SIZE 30

#ifndef elemType
typedef int elemType;
#endif

struct BTreeNode
{
	elemType data;
	BTreeNode *left;
	BTreeNode *right;
}*pNew, *bst;


void init()
{
	pNew = 0;
	bst = 0;
}
void createBSTree(BTreeNode* &head, elemType a)
{	
	if (head == NULL)
	{
		pNew = new BTreeNode();
		pNew->data = a;
		head = pNew;
	}
	else
	{
		if (a < head->data)
		{
			createBSTree(head->left, a);
		}
		else
		{
			createBSTree(head->right, a);
		}
	}
}
void priOrderBTree(BTreeNode *bt)
{
	if (bt != NULL)
	{
		cout << bt->data << " ";
		priOrderBTree(bt->left);
		priOrderBTree(bt->right);
	}
}

void middleOrderBTree(BTreeNode *bt)
{
	if (bt != NULL)
	{
		middleOrderBTree(bt->left);
		cout << bt->data << " ";
		middleOrderBTree(bt->right);
	}
}

void postOrderBTree(BTreeNode *bt)
{
	if (bt != NULL)
	{
		postOrderBTree(bt->left);
		postOrderBTree(bt->right);
		cout << bt->data << " ";
	}
}

int highBTree(BTreeNode *bt)
{
	if (bt != NULL)
	{
		int depth1 = highBTree(bt->left);
		int depth2 = highBTree(bt->right);
		return (depth1 > depth2) ? depth1 + 1 : depth2 + 1;
	}
	else
	{
		return 0;
	}
	
}
int main()
{
	init();
	//elemType x, *px;
	//elemType a[10] = { 'j', 'c', 'b', 'i', 'e', 'h', 'g', 'f', 'd', 'a' };
	elemType a[5] = { 4, 5, 3, 6, 2 };

	cout << "create the binary tree: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " "; 
		createBSTree(bst, a[i]);
	}
	cout << endl;
	cout << endl;

	cout << "priority order: " << endl;
	priOrderBTree(bst);
	cout << endl;
	cout << endl;

	cout << "middle order: " << endl;
	middleOrderBTree(bst);
	cout << endl;
	cout << endl;

	cout << "post order: " << endl;
	postOrderBTree(bst);
	cout << endl;
	cout << endl;

	//print the hight of BTree
	cout << "The hight of Binary Tree" << endl;
	cout << highBTree(bst) << endl;
	
	system("pause");
	return 0;
}