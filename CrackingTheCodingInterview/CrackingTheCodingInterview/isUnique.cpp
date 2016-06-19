#include <iostream>
#include <cstring>
using namespace std;

//O(n*n)
bool isUnique(string str)	
{
	int i, j;
	int length = str.length();
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++) 
		{
			if (str[i] == str[j])
			{
				return false;
				break;
			}
		}
	}
	if (j == length) return true;
}

//O(n)
bool isUnique1(string str)
{
	int v;
	bool s[256];
	//初始化比较大的数组
	memset(s, 0, sizeof(s));
	int length = str.length();
	for (int i = 0; i < length; i++)
	{
		v = (int)(str[i]);
		if (s[v]) 
		{
			return false;
		}
		s[v] = true;
	}
	return true;
}
int main()
{ 
	bool m_flag;
	string str1 = "11";
	string str2 = "12246";
	
	cout << isUnique(str1) << " " << isUnique(str2) << endl;
	cout << isUnique1(str1) << " " << isUnique1(str2) << endl;
	return 0;
}