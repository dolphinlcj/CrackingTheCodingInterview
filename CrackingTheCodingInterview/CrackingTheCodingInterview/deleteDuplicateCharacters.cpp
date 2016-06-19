#include <iostream>
#include <cstring>

using namespace std;


void removeDuplicate(char s[])
{
	int length = strlen(s);
	int i, j;
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (s[i] == s[j])
			{
				s[j] = ' '; //¿Õ¸ñµÄascllÎª32
			}
		}

		if (s[i] != ' ')
		{
			cout << s[i];
		}
	}

	cout << endl;
}


int main()
{
	int i;
	char s[] = "aaaabbb";
	int length = strlen(s);
	
	removeDuplicate(s);

	return 0;
}


