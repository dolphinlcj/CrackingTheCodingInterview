#include <iostream>
#include <map>
using namespace std;
/*
问题描述：找到循环链表的头结点
*/
typedef struct node{
	char data;
	node *next;
}node;

node* init(char a[], int n, int m)
{
	node *head;
	node *p, *q;
	node *nd;
	head = new node();
	head->data = a[0];
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			p = head;
		}
		else
		{
			q = new node();
			q->data = a[i];
			p->next = q;
			p = q;
		}

		if (i == m)
		{
			nd = q;
		}
	}
	p->next = nd;
	return head;
}
/*
@method: using the single link is wrong
*/
char findCircularLinkListHeadNode(node *p)
{
	bool b[256] = {0};
	int temp;
	//memset(b, 0, sizeof(b));
	while (p)
	{
		temp = (int)(p->data);
		if (b[temp])
		{
			return p->data;
		}
		b[temp] = true;
		
		p = p->next;
	}
}

char findCircularLinkListHeadNode1(node *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	node *fast, *slow;

 	fast = head;
	slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			break;
		}
	}
	if (!fast || !fast->next)
	{
		return NULL;
	}

	//when first time to meet, then next time is slow pointer starting from head
	slow = head;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return fast->data;
}

// using map struct, Hash function
char findCircularLinkListHeadNode2(node *head)
{
	map<node*, bool> hash;
	while (head)
	{
		if (hash[head])
		{
			return head->data;
		}
		else
		{
			hash[head] = true; 
			head = head->next;
		}
	}
}
int main()
{
	node *head;
	char a[6] = {'A', 'B', 'C', 'D', 'E', 'C'};
	int aSize = 6;
	int m = 5;
	char headNode;
	
	head = init(a, aSize, m);
	//method 1
	//headNode = findCircularLinkListHeadNode(head);
	//cout << "Circular Link List head node is:" << headNode << endl;

	//method 2
	headNode = findCircularLinkListHeadNode1(head);
	cout << "Circular Link List head node is:" << headNode << endl;

	//method 3
	headNode = findCircularLinkListHeadNode2(head);
	cout << "Circular Link List head node is:" << headNode << endl;

	system("pause");
	return 0;
}