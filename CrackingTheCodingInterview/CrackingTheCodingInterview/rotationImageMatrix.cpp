#include <iostream>
#include <cstring>

using namespace std;

void swap (int *a, int *b)
{
	*a = (*a) ^ (*b);
	*b = (*a) ^ (*b);
	*a = (*a) ^ (*b);

}
void rotationImageMatrix(int a[4][4])
{
	int i, j;
	//对角线先互换
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 4; j++)
		{
				swap(&(a[i][j]), &(a[j][i]));
		}
	}
	//1,4行互换、2,3行互换
	for (j = 0; j < 4; j ++)
	{
		//如果不是4 * 4，则可以写成一个式子
		swap(&(a[0][j]), &(a[3][j]));
		swap(&(a[1][j]), &(a[2][j]));
	}
}
int main()
{
	int c = 12, b = 12;
	int a[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16} };
	
	rotationImageMatrix(a);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a[i][j] << " ";
			
		}
		cout << endl;
	}
	return 0;
}