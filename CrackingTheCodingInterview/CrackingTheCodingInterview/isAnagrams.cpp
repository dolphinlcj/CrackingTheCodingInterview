#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool isAnagrams(string a, string b)
{
	if (a == " " || b == " ")
	{
		return false;
	}
	if (a.length() != b.length())
	{
		return false;
	}
	if (a == b)
	{
		return false;
	}
	//sort
	sort(&a[0], &a[0] + a.length());
	sort(&b[0], &b[0] + b.length());

	if (a == b)
	{
		return true;
	}
	else
		return false;
}

bool isAnagrams2(string a, string b)
{
	int c[256];
	memset(c, 0, sizeof(c));

	if (a == "" || b == "")
	{
		return false;
	}

	if (a.length() != b.length())
	{
		return false;
	}

	if (a == b)
	{
		return false;
	}

	for (int i = 0; i < a.length(); i++)
	{
		c[(int)a[i]] += 1;
		c[(int)b[i]] -= 1;
	}

	for (int i = 0; i < 256; i++)
	{
		if (c[i] != 0)
		{
			return false;
			break;
		}
	}

	return true;
}

int main()
{
	bool m_isAnagrams;
	string a = "lcj1234";
	string b = "ljc321";

//	m_isAnagrams = isAnagrams(a, b);
	m_isAnagrams = isAnagrams2(a, b);
	cout << "Two strings are anagrams: " << m_isAnagrams << endl;

	return 0;
}
