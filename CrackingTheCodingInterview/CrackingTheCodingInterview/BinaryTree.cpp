#include <iostream>
#include <queue>
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

void levelOrderBTree(BTreeNode *bt)
{
	BTreeNode *b;
	
	queue<BTreeNode *> q;
	if (bt != NULL)
	{
		q.push(bt);
	}
	
	while (!q.empty())
	{
		b = q.front();
		cout << b->data; 
		q.pop();

		if (b->left)
		{
			q.push(b->left);
		}
		if (b->right)
		{
			q.push(b->right);
		}

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

bool emptyTree(BTreeNode *bt)
{
	if (bt == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//find element in the BTree
bool findBTree(BTreeNode *bst, elemType x)
{
	if (bst == NULL)
	{
		return NULL;
	}
	else
	{
		if (bst->data == x)
		{
			return true;
		}
		else
		{
			if (findBTree(bst->left, x))
			{
				return true;
			}
			if (findBTree(bst->right, x))
			{
				return true;
			}
			return NULL;
		}
	}
}

//destroy the Binary Tree
void destroyBTree(BTreeNode * &bst)
{
	if (bst != NULL)
	{
		destroyBTree(bst->left);
		destroyBTree(bst->right);
		free(bst);
		bst = NULL;
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

	cout << "level order: " << endl;
	levelOrderBTree(bst);
	cout << endl;
	cout << endl;

	//print the hight of BTree
	cout << "The hight of Binary Tree: " << endl;
	cout << highBTree(bst) << endl;
	cout << endl;

	//find x in the Binary Tree
	cout << "find x address in the Binary Tree:" << endl;
	cout << findBTree(bst, 3) << endl;
	cout << findBTree(bst, 10) << endl;
	cout << endl;
	
	system("pause");
	return 0;
}