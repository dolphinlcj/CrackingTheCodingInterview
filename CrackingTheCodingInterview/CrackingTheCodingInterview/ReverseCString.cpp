#include <iostream>
#include <cstring>

using namespace std;

void reverse(char &a, char &b)
{
	//my method
	char temp;
	temp = a;
	a = b;
	b = temp;

	//other method
	//a = a ^ b;
	//b = a ^ b;
	//a = a ^ b;
}
int main()
{
	char str[] = "abcd123456lvj";
	int i, j;

	i = 0;
	j = strlen(str) - 1; 
//	j = sizeof(str) - 2; //reverse C-style string

	while (i < j)
	{
		reverse(str[i], str[j]);
		i += 1;
		j -= 1;
	}
	cout << str << endl;
	
}