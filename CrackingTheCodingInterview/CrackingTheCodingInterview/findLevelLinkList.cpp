#include <iostream>
#include <cstring>
#include <list>
#include <vector>

using namespace std;
const int maxn = 9;

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
	if (left <= right)
	{
		int mid = (left + right) >> 1;
		newNode(head, a[mid]);

		createMinHighBTree(head->left, a, left, mid - 1);
		createMinHighBTree(head->right, a, mid + 1, right);
	}

}

vector<list<TreeNode*>> findLevelLinkList(TreeNode* head)
{
	vector<list<TreeNode*>> res;
	int level = 0;
	list<TreeNode*> li;
	li.push_back(head);
	res.push_back(li);

	while (!res[level].empty())
	{
		list<TreeNode*> l;
		list<TreeNode*>::iterator it;
		for (it = res[level].begin(); it != res[level].end(); ++it)
		{
			TreeNode *n = *it;
			if (n->left)
			{
				l.push_back(n->left);
			}
			if (n->right)
			{
				l.push_back(n->right);
			}
		}
		++level;
		res.push_back(l);
	}

	return res;
}

void print(vector<list<TreeNode*>> res)
{
	vector<list<TreeNode*> >::iterator vit;
	for (vit = res.begin(); vit != res.end(); vit++)
	{
		list<TreeNode*> li = *vit;
		list<TreeNode*>::iterator lit;
		for (lit = li.begin(); lit != li.end(); lit++)
		{
			TreeNode *n = *lit;
			cout << n->data << " ";
		}
		cout << endl;
	}
	
}

int main()
{
	init();
	
	int a[maxn] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	createMinHighBTree(bst, a, 0, maxn - 1);

	vector<list<TreeNode*>> res;
	res = findLevelLinkList(bst);
	print(res);
	
	system("pause");
	return 0;
}