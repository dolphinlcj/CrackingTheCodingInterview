#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/*
问题：check一颗树，是否平衡，这里的平衡指：任意两个叶子结点离根节点距离不大于1；
而不是判断平衡二叉树：即，空树或左右子树的高度差绝对值不超过1；
*/

const int maxn = 100;

struct Node{
	int key;
	Node *lchild, *rchild, *parent;
};

Node *head, *p, node[maxn];
int cnt;

void init()
{
	head = NULL;
	p = NULL;
	memset(node, '\0', sizeof(node));
	cnt = 0;
}

void insert(Node* &head, int x)
{
	if (head == NULL)
	{
		node[cnt].key = x;
		node[cnt].parent = p;
		head = &node[cnt];
		cnt += 1;
		return;
	}
	p = head;
	if (x < head->key)
	{
		insert(head->lchild, x);
	}
	else
	{
		insert(head->rchild, x);
	}
}

int d = 0, num = 0, dep[maxn];
void getDepth(Node *head)
{
	if (head == NULL)
	{
		return;
	}
	d += 1;
	//middle order
	getDepth(head->lchild);

	//get data of leaf nodes and num of leaf nodes
	if (head->lchild == NULL && head->rchild == NULL)
	{
		dep[num] = d;
		num += 1;
	}

	getDepth(head->rchild);
	d -= 1;
}
bool checkTreeBalance(Node *head)
{
	if (head == NULL)
	{
		return true;
	}
	
	getDepth(head);
	
	int max = dep[0];
	int min = dep[0];
	
	for (int i = 0; i < num; ++i)
	{
		if (dep[i] > max)
		{
			max = dep[i];
		}
	
		if (dep[i] < min)
		{
			min = dep[i];
		}
	}
	
	if (max - min > 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	//a, b, c 为 array
	int a[12] = { 5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12 };
	int b[7] = { 4, 2, 7, 1, 3, 5, 8 };
	int c[3] = {3, 2, 4};

	init();
	
	for (int i = 0; i < 3; ++i)
	{
		insert(head, c[i]);
	}

	cout << checkTreeBalance(head) << endl;
	
	system("pause");
	return 0;
}