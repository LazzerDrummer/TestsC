#include <iostream>

using namespace std;

int main()
{
	char s[20], x[20];
	cin.get(s, 21);
	if (strlen(s) % 2 == 0) strcpy_s(x, s);
	else
	{
		strncpy_s(x, s, strlen(s) / 2);
		strcat_s(x, strchr(s, s[(strlen(s) / 2) + 1]));
	}
	cout << x;
	cin.ignore();
	cin.get();
}