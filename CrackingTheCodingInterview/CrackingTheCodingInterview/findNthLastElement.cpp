#include <iostream>
using namespace std;

/*
问题：返回单链表倒数第n个结点的值
*/

typedef struct node{
	int data;
	node *next;
}node;

node* init(int a[], int n)
{
	node *head, *p, *q;
	head = new node();
	head->data = a[0];
	int i;
	for (i = 0; i < n; i++)
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
	}
	return head;
}

void print(node* p)
{
	while (p)
	{	 
		cout << p->data << endl;
		p = p->next;
	}
}

int findNthLastElement(node* head, int n)
{
	node *p, *q;
	p = head;
	q = head;
	int length = 0;
	int m;
	while (p)
	{
		length++;		
		p = p->next;
	}
	m = length - n;
	while (m > 0 && q)
	{
		q = q->next;
		m--;
	}
	
	if (q)
	{
		return q->data;
	}
}
//the method is double pointer 
int findNthLastElement1(node* head, int n)
{
	node *p, *q;
	q = head;
	p = head;
	
	if (n < 1 || head == NULL) 
		return -1;
	while (n > 0 && p)
	{
		p = p->next;
		n--;
	}
	if (n > 0)  return NULL; 
	while (p)
	{
		p = p->next;
		q = q->next;
	}

	if (!p)
	{
		return q->data;
	}
}
int main()
{
	int a[10] = {1, 2, 5, 8, 3, 6, 9, 2, 4, 10};
	int aSize = 10;
	int n = 4;
	int data;

	node *head;
	head = init(a, aSize);
	print(head);
	//n is the nth last element of single link list
	data = findNthLastElement(head, n);
	cout << "The n last element is : " << data << endl;
	
	//double pointer 
	data = findNthLastElement1(head, n);
	cout << "The n last element is : " << data << endl;
	
	system("pause");
	return 0;
}