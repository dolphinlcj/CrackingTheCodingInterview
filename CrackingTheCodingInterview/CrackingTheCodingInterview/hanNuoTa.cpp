#include <iostream>
using namespace std;
/*
问题：1、用递归实现汉诺塔问题
      2、用stack数据结构实现汉诺塔问题
*/

void move(int n, char a, char b, char c)
{
	if (n == 1)
	{
		cout << n << ": "<< a << "->" << c << endl;
	}
	else
	{
		move(n-1, a, c, b);
		cout << n << ": "<< a << "->" << c << endl;
		move(n-1, b, a, c);
	}
}
int main()
{
	int n;
	cout << "Input the total number of cubes: ";
	cin >> n;

	move(n, 'A', 'B', 'C');
	system("pause");
	return 0;
}
