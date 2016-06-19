#include <iostream>
#include <cstring>
#include <string>

using namespace std;

bool isSubString(string a, string b)
{
	if (a.find(b) != -1)
	{
		//cout << "b is a substring of a" << endl;
		return true;
	}
	else
	{
		return false;
	}
}
bool isRotationString(string a, string b)
{
	if (a.length() != b.length() || a.length() <= 0)
		return false;
	return isSubString(a + a, b);
}

int main()
{
	int i = 0;
	string a, b;
	a = "lcjis";
	b = "jislc";
	cout << isRotationString(a, b) << endl;
	return 0;
}