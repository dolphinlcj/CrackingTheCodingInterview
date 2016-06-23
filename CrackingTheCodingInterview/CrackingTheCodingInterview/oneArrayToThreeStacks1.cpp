#include <iostream>
using namespace std;

typedef struct node
{
	int var, preIdx;
}node;

class stack3
{
public:
	stack3(int totalSize = 900)
	{
		buf = new node[totalSize];
		ptop[0] = ptop[1] = ptop[2] = -1;
		this->totalSize = totalSize;
		cur = 0; 
	}
	~stack3()
	{
		delete[] buf;
	}
	void push(int stackNum, int val)
	{
		buf[cur].var = val;
		buf[cur].preIdx = ptop[stackNum];
		ptop[stackNum] = cur;
		++cur;
	}

	void pop(int stackNum)
	{
		ptop[stackNum] = buf[ptop[stackNum]].preIdx;
	}
	int top(int stackNum)
	{
		return buf[ptop[stackNum]].var;
	}
	bool empty(int stackNum)
	{
		ptop[stackNum] = -1;
	}
private:
	node *buf;
	int ptop[3];
	int totalSize;
	int cur;
};
int main()
{
	stack3 m_stack;
	for (int i = 0; i < 10; i++)
	{
		m_stack.push(0, i);
	}
	for (int i = 10; i < 20; i++)
	{
		m_stack.push(1, i);
	}
	for (int i = 20; i < 30; i++)
	{
		m_stack.push(2, i);
	}
	for (int i = 0; i < 3; i++)
	{
		cout << m_stack.top(i) << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		m_stack.pop(i);
		cout << m_stack.top(i) << endl;
	}
	return 0;
}









