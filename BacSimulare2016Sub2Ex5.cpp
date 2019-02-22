#include <iostream>
using namespace std;
int main()
{
	int v[30] = { 0 };
	char c;
	while (cin.get(c))
	{
		if (c != ' ') v[(int)c - 'a']++;
		if (c == '\n') break;
	}
	while (cin.get(c))
	{
		if (c != ' ') v[(int)c - 'a']--;
		if (c == '\n') break;
	}
	for (int i = 0; i < 30; i++) if (v[i] != 0) 
	{ 
		cout << "NU"; 
		cin.ignore();
		cin.get();
		return 0;
	}
	cout << "DA";
	cin.ignore();
	cin.get();
}