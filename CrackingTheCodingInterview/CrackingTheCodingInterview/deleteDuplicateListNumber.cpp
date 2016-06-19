#include <iostream>
#include <cstring>

using namespace std;

typedef struct node 
{
	int data;
	node* next;
}node;

node* init(int a[], int n)
{
	node *head, *p;
	for (int i = 0; i < n; i++)
	{
		node *np = new node();
		np->data = a[i];
		if (i == 0) 
		{
			head = p = np;
			continue;
		}

		p->next = np;
		p = np;
	}
	return head;
}
//不允许临时缓存
void deleteDuplicateListNumber(node *head)
{
	node * p;
	node * q;
	node * c;
	
	c = head;
	if (head == NULL)
	{
		return;
	}
	while (c)
	{
		p = c;
		q = c->next;
		int d = c->data;
		while (q)
		{
			if (d == q->data)
			{
				node *t = q;
				p->next = q->next;
				q = p->next;
				delete t;
			}
			else 
			{
				p = q;                  //很重要这一步，删除操作是在两个连续的指针上运作的
				q = q->next;
			}
		}
		c = c->next;
	}
}
void deleteDuplicateListNumber1(node *head)
{
	node * p;
	node * q;
	node * c;
	int d;
	bool hash[100];
	memset(hash, 0, sizeof(hash));
	
	p = head;
	hash[p->data] = true;
	q = p->next;
	while (q)
	{
		d = q->data;
		if (hash[d])
		{
			node *t = q;
			p->next = q->next;
			q = p->next;
			delete t;
		}
		else
		{
			hash[d] = true;
			p = q;
			q = q->next;
		}
	}
	
}
void print(node* head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{ 
	const int n = 10;
	int a[n] = { 3, 2, 1, 3, 5, 6, 2, 6, 3, 1 };
	node *head;
	
	head = init(a, n);
	//deleteDuplicateListNumber(head);
	deleteDuplicateListNumber1(head);
	print(head);
	return 0;
}