#include <iostream>
using namespace std;

const int STACK_SIZE = 100;
const int STACK_NUM = 10;

/*
问题：模拟几个stack，合成的一个stack，实现pop、push等操作，并考虑每个小的stack的capacity。
并实现popAt(idx),对指定的idx的小stack实现pop操作。
*/
class stack
{
public:
	stack(int capa = STACK_SIZE)
	{
		buf = new int[capa];
		cur = -1;
		capacity = capa;
	}
	~stack()
	{
		delete[] buf;
	}
	void push(int data)
	{
		cur += 1;
		buf[cur] = data;
	}
	void pop()
	{
		cur -= 1;
	}
	int top()
	{
		return buf[cur];
	}
	bool empty()
	{
		return cur == -1;
	}
	bool full()
	{
		return cur == capacity - 1;
	}
private:
	int *buf;
	int cur;
	int capacity;   //the capacity of stack
};

class SetOfStacks             //without popAt(idx)
{
public:
	SetOfStacks(int capa = STACK_NUM)
	{
		st = new stack[capa];
		cur = 0;
		capacity = capa;
	}
	~SetOfStacks()
	{
		delete[] st;
	}

	void push(int data)
	{
		if (st[cur].full())
		{
			cur += 1;
		}
		st[cur].push(data);			
	} 

	void pop()
	{
		if (st[cur].empty())
		{
			cur -= 1;
		}
		st[cur].pop();
	}
	
	int top()
	{
		if (st[cur].empty())
		{
			cur -= 1;
		}
		return st[cur].top();
	}
	
	bool empty()
	{
		if (cur == 0)
		{
			st[0].empty();
		}
		else
		{
			return false;
		}
	}

	bool full()
	{
		if (cur == capacity - 1)
		{
			return st[cur].full();
		}
		else
		{
			return false;
		}
	}
private:
	stack* st;
	int cur;
	int capacity;
};

class SetOfStacks1
{
private:
	stack *st;
	int cur;
	int capacity;

public:
	SetOfStacks1(int capa = STACK_NUM)
	{
		st = new stack[capa];
		cur = 0;
		capacity = capa;
	}
	~SetOfStacks1()
	{
		delete[] st;
	}
	void push(int data)
	{
		if (st[cur].full())
		{
			cur += 1;
		}
		st[cur].push(data);
	}
	
	void pop()
	{
		while (st[cur].empty())
		{
			cur -= 1;
		}
		st[cur].pop();
	}

	void popAt(int idx)
	{
		while (st[idx].empty())
		{
			idx -= 1;
		}
		st[idx].pop();
	}
	
	int top()
	{
		while (st[cur].empty())
		{
			cur -= 1;
		}
		return st[cur].top();
	}
	
	bool empty()
	{
		while (cur != -1 && st[cur].empty())
		{
			cur -= 1;
		}
		if (cur == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool full()
	{
		if (cur == capacity - 1)
		{
			return st[cur].full();
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	//Test the stack
	stack mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	cout << mstack.top() << endl;
	mstack.pop();
	cout << mstack.top() << endl;

	//Test SetOfStacks
	SetOfStacks ss;
	for (int i = 0; i < STACK_SIZE + 1; i++)
	{
		ss.push(i);
	}
	while (!ss.empty())
	{
		cout << ss.top() << endl;
		ss.pop();
	}

	//Test SetOfStacks1
	SetOfStacks1 ss1;
	for (int i = 0; i < 3 * STACK_SIZE + 1; ++i)
	{
		ss1.push(i);
	}
	
	for (int i = 0; i < STACK_SIZE; ++i)
	{
		ss1.popAt(0);
		ss1.popAt(2);
	}
	ss1.popAt(3);
	
	while (!ss1.empty())
	{
		cout << ss1.top() << endl;
		ss1.pop();
	}
	
	system("pause");
	return 0;
}