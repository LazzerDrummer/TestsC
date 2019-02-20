#include <iostream>
using namespace std;
int main()
{
	int i, j, c = 0, u = 0;
	char s[101];
	cin.get(s, 102);
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ')
		{
			if (c % 2 == 0 && c != 0)
			{
				strcpy(s + i - c, s + i - 1);
				i -= c;
				s[i] = '#';
				c=0; u=1;
			}
			if (c % 2 == 1)
			{
				c = 0; continue;
			}
		}
		else c++;
	}
	if (u == 0) { cout << "nu exista"; cin.ignore(); cin.get(); return 0;}
	printf("%s", s);
	cin.ignore();
	cin.get();
}