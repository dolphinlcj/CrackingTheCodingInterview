#include <iostream>
#include <stack>
using namespace std;

/*
问题：用两个stack数据结构实现Queue
方法：blog作者的写法2,减少数据在stack中的移动，小的改进
*/
template <typename T>

class MyQueue
{
public:
	MyQueue()
	{
	}

	~MyQueue()
	{
	}

	void push(T val)
	{
		move(sout, sin);
		sin.push(val);
	}

	void pop()
	{
		move(sin, sout);
		sout.pop();
	}

	T front()
	{
		move(sin, sout);
		return sout.top();
	}
	T back()
	{
		move(sout, sin);
		return sin.top();
	}

	int size()
	{
		return sin.size() + sout.size();
	}
	bool empty()
	{
		return (sin.empty() && sout.empty());
	}

	void move(stack<T> &src, stack<T> &dst)
	{
		if (dst.empty())
		{
			while (!src.empty())
			{
				dst.push(src.top());
				src.pop();
			}
		}
	}

private:
	stack<T> sin, sout;
};

int main()
{
	MyQueue<int> q;
	for (int i = 0; i < 10; i++)
	{
		q.push(i);
	}

	cout << q.front() << " " << q.back() << endl;
	cout << endl;

	q.pop();
	q.push(10);
	cout << q.front() << " " << q.back() << endl;
	cout << endl;

	cout << q.size() << " " << q.empty() << endl;

	system("pause");
	return 0;
}