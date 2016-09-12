#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
struct Node{
	int key;
	Node *left, *right, *parent;
};

Node node[maxn];
int cnt;

void init()
{
	memset(node, '\0', sizeof(node));
	cnt = 0;
}

void createBtree(Node * &head, Node *parent, int a[], int start, int end)
{
	if (start <= end){
		int middle = (start + end) >> 1;
		node[cnt].key = a[cnt];
		node[cnt].parent = parent;
		head = &(node[cnt]);
		cnt = cnt + 1;
		
		createBtree(head->left, head, a, start, middle - 1);
		createBtree(head->right, head, a, middle + 1, end);
	}
}

bool match(Node* r1, Node* r2)
{
	if (r1 == NULL && r2 == NULL)
	{
		return true;
	}
	else if (r1 == NULL || r2 == NULL)
	{
		return false;
	}
	else if (r1->key != r2->key)
	{
		return false;
	}
	else
	{
		return match(r1->left, r2->left) && match(r1->right, r2->right);
	}
}

bool subTree(Node* r1, Node* r2)
{
	if (r1 == NULL)
	{
		return false;
	}
	else if (r1->key == r2->key)
	{
		if (match(r1, r2))
		{
			return true;
		}
	}
	else
	{
		return subTree(r1->left, r2) || subTree(r1->right, r2);
	}
}

bool contain_tree(Node* r1, Node* r2)
{
	if (r2 = NULL){
		return true;
	}
	else {
		return subTree(r1, r2);
	}
}
int main()
{
	int a1[] = {0, 1, 2, 3, 4, 5, 6};
	int a2[] = {0, 1, 2};
	Node *r1 = NULL, *r2 = NULL;

	init();
	createBtree(r1, NULL, a1, 0, 6);
	createBtree(r2, NULL, a2, 0, 2);

	if (contain_tree(r1, r2))
	{
		cout << "r2 is the subtree of r1" << endl;
	}
	else
	{
		cout << "r2 is not the subtree of r1" << endl;
	}
	return 0;
}
