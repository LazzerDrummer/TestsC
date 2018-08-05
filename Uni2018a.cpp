#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int l; cin >> l;
	cin.ignore();
	int i = l, f = 0, p, j;
	char s[10000];
	cin.get(s, 10001);
	while (i < strlen(s))
	{
		while (s[i] != 32) i--;
		p = i - 1;
		for (j = f; j <= p; j++) cout << s[j];
		cout << endl;
		f = i + 1;
		i = i + l + 1;
	}
	for (j = f; j <= strlen(s); j++)cout << s[j];
	cin.ignore();
	cin.get();
}