#include <iostream>
using namespace std;

typedef struct node
{
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

node *addLinkList(node *p, node *q)
{
	node *res, *pre = NULL;
	if (p == NULL)
		return q;
	if (q == NULL)
		return p;
	
	int flag = 0;//进位标志
	while (p && q)
	{
		int t = p->data + q->data + flag;
		node *r = new node();
		r->data = t % 10;
		
		if (pre)
		{
			pre->next = r;      //最后是倒序输出还是正序输出
			pre = r;
		}
		else
		{
			res = r;
			pre = r;
		}

		flag = t / 10;
		
		p = p->next;
		q = q->next;
	}

	while (p)
	{
		int t = p->data + flag;
		node *r = new node();
		r->data = t % 10;
		pre->next = r;
		pre = r;
		flag = flag / 10;
		p = p->next;
	}
	
	while (q)
	{
		int t = q->data + flag;
		node *r = new node();
		r->data = t % 10;
		pre->next = r;
		pre = r;
		flag = flag / 10;
		q = q->next;
	}

	if (flag > 0)
	{
		node *r = new node();
		r->data = flag;
		pre->next = r;
	}
	return res;
}

void print(node * head)
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
	int n = 4;
	int a[] = { 1, 2, 9, 3 };
	int m = 3;
	int b[] = { 9, 9, 2 };

	node *p, *q;
	node *res;

	p = init(a, n);
	q = init(b, m);

	res = addLinkList(p, q);

	if (p)
	{
		print(p);
	}
	if (q)
	{
		print(q);
	}
	if (res)
	{
		print(res);
	}
	return 0;
}
