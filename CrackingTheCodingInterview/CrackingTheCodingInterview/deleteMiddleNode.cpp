#include <iostream>
#include <string>
/*
问题描述：删除单链表中间的结点，只返回那个结点的指针
*/
using namespace std;

typedef struct node
{
	int data;
	node* next;
}node;

node* init(int s[], int n)
{
	node *head, *p, *q;
	
	head = new node();
	head->data = s[0];
	
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			p = head;
		else
		{
			q = new node();
			p->next = q;
			p = q;
			p->data = s[i];
		}
	}
	return head;
}

void exchange(int &a, int &b)
{
	int temp;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

bool remove(node *c)
{
	node *p;
	p = c->next;
	//if the c is the last pointer with problem
	exchange(c->data, p->data);
	
	if (c == NULL || p == NULL)
	{
		return false;
	}

	node *t = p;
	c->next = p->next;
	p = c->next;
	delete t;
	return true;
}

void print(node *head)
{
	cout << "The link list is:" << endl;
	while(head)
	{
		cout << head ->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int middle = 9;
	int n = 10;
	int s[] = {9, 2, 1, 3, 5, 6, 2, 6, 3, 1};
	//init the data
	node* head = init(s, n);
	
	node* c = head;
	
	//only know the point of middle node
	for (int i = 1; i < middle; i++)
	{
		c = c->next;
	}
	
	print(head);

	if (remove(c))
	{
		print(head);
	}
	else
	{
		cout << "failure" << endl;
	}
	
	return 0;
}