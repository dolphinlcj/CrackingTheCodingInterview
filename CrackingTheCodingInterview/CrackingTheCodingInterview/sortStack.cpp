#include <iostream>
#include <stack>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <functional>       //这句话没有，下面的优先级队列，第三个参数是错误的
using namespace std;

class sortStack
{
public:
	stack<int> sort1(stack<int> s)
	{
		stack<int> t;
		while (!s.empty())
		{
			int data = s.top();
			s.pop();
			while (!t.empty() && t.top() > data)
			{
				s.push(t.top());
				t.pop();
			}
			t.push(data);
		}
		return t;
	}

	void sort2(stack<int> &s)
	{
		priority_queue<int, vector<int>, greater<int> > q; //最小值优先队列
		//priority_queue<int, vector<int>, less<int> > q;
		while (!s.empty())
		{
			q.push(s.top());
			s.pop();
		}
		while (!q.empty())
		{
			s.push(q.top());
			q.pop();
		}
	}
};
int main()
{
    //随机数生成器
	//srand((unsigned)time(0));
	//rand()/(RAND_MAX + 1.0)：０～１
	//rand() : 0 ～ 0x7ffff 即：0~32767
	//cout << rand() % 100 << endl;

	const int N = 5;
	int a[N] = {5, 2, 1, 6, 4};
	
	stack<int> st;
	sortStack s;
	
	for (int i = 0; i < N; i++)
	{
		st.push(a[i]);
	}
	//method1
	//st = s.sort1(st);
	
	//method2
	s.sort2(st);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	
	system("pause");
	return 0;
}