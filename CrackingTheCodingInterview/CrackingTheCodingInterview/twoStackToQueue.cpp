#include <iostream>
#include <stack>
using namespace std;

/*
问题：用两个stack数据结构实现Queue
方法：我自己的写法
*/
class MyQueue
{
public:
	MyQueue()
	{		
		//index1 = -1;
		//index2 = -1;
	}
	~MyQueue()
	{
	}
	//push 
	void queuePush(int data)
	{
		while (!st2.empty())
		{
			st1.push(st2.top());
			st2.pop();
		}
		st1.push(data);
	}
	//pop
	void queuePop()
	{
		while (!st1.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}
		cout << "Data output from the queue : " << st2.top() << endl;
	
		st2.pop();
	}
	//top
	int queueTop()
	{
		return st2.top();
	}
	//empty
	bool queueEmpty()
	{
		if (st1.empty() && st2.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	stack<int> st1, st2;
	//int index1, index2;
};

int main()
{
	MyQueue queue;
	for (int i = 0; i < 5; i++)
	{
		queue.queuePush(i);
	}
	
	for (int i = 0; i < 5; i++)
	{
		queue.queuePop();
	}

	queue.queuePush(5);
	queue.queuePop();

	system("pause");
	return 0;
}