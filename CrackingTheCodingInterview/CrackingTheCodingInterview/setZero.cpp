#include <iostream>
#include <cstring>
#define M 4
#define N 4
using namespace std;

void setZero(int a[][N], int m, int n) 
{
	int i, j;
	bool row[M], col[N];
	//定义的数组，别忘了初始化
	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));
	
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
			{
				row[i] = true;
				col[j] = true;
			}
		}
	}
	
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (row[i] || col[j])
			{
				a[i][j] = 0;
			}
		}
}
void print(int a[][N], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int main() 
{
	int m, n;
	int a[M][N] = { { 1, 2, 3, 0 }, { 1, 3, 0, 4 }, { 2, 0, 1, 5 }, {3, 4, 1, 9} };
	m = M;
	n = N;
	setZero(a, m, n);
	print(a, m, n);
	return 0;
}