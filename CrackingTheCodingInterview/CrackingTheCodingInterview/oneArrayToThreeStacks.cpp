#include <iostream>

using namespace std;

class stack1
{
public:
	stack1(int size = 300)
	{
		stack = new int[size * 3];
		ptop[0] = ptop[1] = ptop[2] = -1;
		this->size = size;
	}
	~stack1()
	{
		delete[] stack;
	}

	void push(int stackNum, int data)
	{
		int id = stackNum * size + ptop[stackNum] + 1;
		stack[id] = data;
		++ptop[stackNum];
	}
	void pop(int stackNum)
	{
		--ptop[stackNum];
	}
	int top(int stackNum)
	{
		int index = stackNum * size + ptop[stackNum];
		return stack[index];
	}
	bool empty(int stackNum)
	{
		return ptop[stackNum] = -1;
	}
private:
	int *stack;
	int ptop[3];
	int size;
};

int main()
{
	stack1 m_stack;
	for (int i = 0; i < 10; i++)
	{
		m_stack.push(0, i);
	}

	for (int i = 10; i < 20; i++)
	{
		m_stack.push(1, i);
	}

	for (int i = 100; i < 110; i++)
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

	m_stack.push(0, 123);
	m_stack.push(1, 222);
	m_stack.push(2, 334);
	for (int i = 0; i < 3; i++)
	{
		cout << m_stack.top(i) << endl;
	}

	system("pause");
	return 0;
}