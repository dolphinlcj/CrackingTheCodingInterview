#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 6

using namespace std;

typedef struct TreeNode
{
	int data;
	TreeNode *left, *right;
}TreeNode;

TreeNode *bst, *p;

void init()
{
	//memset(TreeNode, '\0', sizeof(TreeNode));
}
void createMinHighBTree(TreeNode * &head, int a[], int left, int right)
{
	if (left <= right)
	{
		int mid = left + (left + right) >> 1;
		p = new TreeNode();
		p->data = a[mid];

		createMinHighBTree(p->left, a, left, mid -1);
		createMinHighBTree(p->right, a, mid+1, right);
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
	//return max(getHight(head->left), getHight(head->right)) + 1;
}

int main()
{
	init();
	TreeNode *head;
	int a[maxn] = {1, 3, 5, 8, 9, 11};
	
	createMinHighBTree(head, a, 0, maxn);
	cout << getHight(head) << endl;
	system("pause");
	return 0;
}