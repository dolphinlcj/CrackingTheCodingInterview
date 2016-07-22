#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 9

using namespace std;

typedef struct TreeNode
{
	int data;
	TreeNode *left, *right;
}TreeNode;

TreeNode *bst, *p;

void init()
{
	p = NULL;
	bst = NULL;
}

void newNode(TreeNode* &vNode, int data)
{
	vNode = new TreeNode;
	vNode->data = data;
	vNode->left = NULL;
	vNode->right = NULL;
}

void createMinHighBTree(TreeNode * &head, int a[], int left, int right)
{
	/*
	if (head == NULL)
	{
		mid = (left + right) >> 1;
		p = new TreeNode();
		p->data = a[mid];
		head = p;
	}
	else
	{
		if (left <= right)
		{
			createMinHighBTree(head->left, a, left, mid - 1);
			createMinHighBTree(head->right, a, mid + 1, right);
		}
			
	}
    */

	if (left <= right)
	{
		int mid = (left + right) >> 1;
		newNode(head, a[mid]);

		createMinHighBTree(head->left, a, left, mid-1);
		createMinHighBTree(head->right, a, mid + 1, right);
	}
	
}

int getHight(TreeNode *head)
{
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		int leftHight = getHight(head->left);
		int rightHight = getHight(head->right);
		return (leftHight > rightHight) ? leftHight + 1 : rightHight + 1;
	}
	//second method
	//if (head == NULL) return 0;
	//return max(getHight(head->left), getHight(head->right)) + 1;
}

int main()
{
	init();
	int a[maxn] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	
	createMinHighBTree(bst, a, 0, maxn-1);
	cout << getHight(bst) << endl;
	
	system("pause");
	return 0;
}