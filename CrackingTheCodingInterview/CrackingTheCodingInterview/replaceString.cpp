#include <iostream>
#include <cstring>

using namespace std;

//array space is enough
void replace2(char *c)
{
	int i, j;
	int newlength;
	int cnt = 0;
	if (c == NULL) return;
	int length = strlen(c);
	if (length == 0) return;
	//count the number of space
	for (i = 0; i < length; i++)
	{
		if (c[i] == ' ')
		{
			cnt += 1;
		}
	}
	
	newlength = 2 * cnt + length;
	c[newlength] = '\n';               //*******the space must set the rear
	newlength -= 1;

	for (j = length - 1, i = newlength; j >= 0; j--) //边界要注意的
	{
		if (c[j] == ' ')
		{
			c[i] = '%';
			c[i - 1] = '0';
			c[i - 2] = '2';
			i -= 3;
		}
		else
		{
			c[i] = c[j];
			i -= 1;
		}
	}


}
int main()
{
	const int len = 100;
	char c[len] = "lcj is a good boy";
	replace2(c);
	cout << c;
	return 0;
}