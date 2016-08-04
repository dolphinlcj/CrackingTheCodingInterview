#include <iostream>
using namespace std;

void init()
{
}

void func(int a[], int n)
{	
	//反着写，正过来写，a[0]就会改变为1
	for (int i = n - 1; i >= 0; i--)
	{
		a[i] /= a[0];
	}

}

void print(int *a, int n)
{	
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[] = {2, 2, 3, 4, 5};
	int n = 0;
	n = sizeof(a) / 4;
	//cout << n << endl;
	
	init();

	if (a[0] == 0) 
	{
		cout << "除数为0, 则无法计算array每个元素除以它的第一个元素" << endl;
	}
	else
	{
		func(a, n);
		print(a, n);
	}
	
	return 0;
}