#include <iostream>
#include <cstring>

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
	memset(node, '\0', sizeof(node));
	p = NULL;
}

void createMinTree(Node* &head, Node* parent, int a[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) >> 1;
		node[cnt].data = a[mid];
		node[cnt].parent = parent;
		head = &node[cnt];
		cnt += 1;
		
		createMinTree(head->left, head, a, start, mid -1);
		createMinTree(head->right, head, a, mid + 1, end);
	}
}

Node* getMinialNode(Node *node)
{
	if (node == NULL)
	{
		return NULL;
	}
	while (node->left)
	{
		node = node->left;
	}
	return node;
}

Node* successor(Node* node)
{
	if (node == NULL)
	{
		return NULL;
	} 
	//找到不为null的右结点的最左子结点
	if (node->right)
	{
		return getMinialNode(node->right);
	}
	//否则，找到左节点的parent的结点，或者找到右结点的最上层的结点
	Node* q = node->parent;
	while (q && q->right == node)
	{
		node = q;
		q = q->parent;
	}
	
	return q;
}
int main()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	init();

	Node *head = NULL;
	createMinTree(head, NULL, a, 0, 9);
	cout << "the head node is " << head->data << endl;

	cout << "the successor of head is: " << (successor(head))->data << endl;
	system("pause");
	return 0;
}