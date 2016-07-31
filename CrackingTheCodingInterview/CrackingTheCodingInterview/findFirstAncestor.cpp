#include <iostream>
#include <cstring>
#include <map>

using namespace std;

const int maxn = 100;
struct Node
{
	int data;
	Node *left, *right, *parent;
};

Node *p, node[maxn];
int cnt;

void init()
{
	cnt = 0;
	p = NULL;
	memset(node, '\0', sizeof(node));
}

void createBTree(Node* &head, Node* parent, int a[], int start, int end)
{
	if (start <= end)
	{
		int mid = (start + end) >> 1;
		node[cnt].data = a[mid];
		node[cnt].parent = parent;
		head = &node[cnt];
		cnt += 1;

		createBTree(head->left, parent, a, start, mid -1);
		createBTree(head->right, parent, a, mid + 1, end);
	}
}
Node* findFirstAncestor(Node* n1, Node* n2)
{
	if (n1 == NULL || n2 == NULL)
	{
		return NULL;
	}
	
	map<Node*, bool> m;
	while (n1)
	{
		m[n1] = true;
		n1 = n1->parent;
	}
	
	while (n2 && !m[n2])
	{
		n2 = n2->parent;
	}
	return n2;
}

Node* search(Node* head, int x)
{
	if (head == NULL)
	{
		return NULL;
	}
	else if (x == head->data)
	{
		return head;
	}
	else if (x <= head->data)
	{
		search(head->left, x);
	}
	else
	{
		search(head->right, x);
	}
}
int main()
{
	init();
	
	int a[] = {0, 1, 2, 3, 4, 5, 6};
	
	Node* head = NULL;
	createBTree(head, NULL, a, 0, 6);
	
	Node * n1 = search(head, 0);
	Node * n2 = search(head, 4);
	cout << n1->data << " " << n2->data << endl;
	
	Node * n = findFirstAncestor(n1, n2);
	cout << n->data << endl;
	
	system("pause");
	return 0;
}