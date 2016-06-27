#include <iostream>
using namespace std;

/*二分法思想：1、将一组数先排序 
2、总是和数组中间的数比较，如果比它大，搜索右边，如果比它小，搜索左边的；相等则找到。
*/
//递归的方法
int BinarySearch1(int a[], int low, int high, int key) 
{
	int mid = (low + high) / 2;
	if (low > high)
	{
		return -1;
	}
	if (key > a[mid])
	{
		return BinarySearch1(a, mid+1, high, key);
	}
	else if(key < a[mid])
	{
		return BinarySearch1(a, low, mid - 1, key);
	}
	else
	{
		return mid;
	}
}

//非递归的方法
int BinarySearch2(int a[], int aSize, int key)
{
	int low = 0;
	int high = aSize - 1;
	int mid;
	//int mid = (low + high) / 2;
	
	while (low < high)
	{
		mid = (low + high) / 2;
		if (key > a[mid])
		{
			low = mid + 1;
		}
		if (key < a[mid])
		{
			high = high - 1;
		}
		if (key == a[mid])
		{
			return mid;
		}
	}
}	
int main()
{
	int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	int key; //要搜索的数

	cin >> key;

	cout << "The position of key is：" << BinarySearch1(a, 0, 7, key) << endl;
	cout << "The position of key is: " << BinarySearch2(a, 8, key) << endl;
	
	system("pause");
	return 0;

}