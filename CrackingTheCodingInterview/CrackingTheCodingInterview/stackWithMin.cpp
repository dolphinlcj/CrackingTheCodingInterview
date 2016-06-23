#include <iostream>
using namespace std;

const int MAX_INT = ~(1 << 31);
class stack
{
public:
	stack(int size = 1000)
	{
		buf = new int[size];
		cur = -1;
	}
	~stack()
	{
		//delete[] buf;
	}
	void push(int val)
	{
		cur++;
		buf[cur] = val;
	}
	void pop()
	{
		--cur;
	}
	int top()
	{
		return buf[cur];
	}
	bool empty()
	{
		return cur == -1;
	}
private:
	int *buf;
	int cur;

};
class stackWithMin
{
public:
	stackWithMin(){};
	~stackWithMin(){};
	void push(int val)
	{
		s1.push(val);
		if (val <= min())
			s2.push(val);
	}
	void pop()
	{
		if (s1.top() == min())
		{
			s2.pop();
		}
		s1.pop();
	}
	int top()
	{
		return s1.top();
	}
	int min()
	{
		if (s2.empty())
			return MAX_INT;
		return s2.top();
	}
	bool empty()
	{
		return s1.empty();
	}
private:
	stack s1, s2;
};

int main()
{
	stack s;
	s.push(1);
	cout << s.top() <<endl;

	stackWithMin m_stack;
	for (int i = 0; i < 10; i++)
	{
		m_stack.push(i);
	}
	cout << "The current top of stack is:"<< m_stack.top() << endl;
	cout <<"The min number is:" << m_stack.min() << endl;

	m_stack.push(-10);
	cout <<"The min number is:" << m_stack.min() << endl;

	m_stack.pop();
	cout << "After pop the min number is:"<< m_stack.min() << endl;
	
	system("pause");
	return 0;
}