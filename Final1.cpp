#include <iostream>
#include <fstream>
using namespace std;
int v[101];
int main()
{
	int n, s, c, b = 0;
	ifstream f("bac.txt");
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		f >> s;
		while (s > 9)
		{
			c = s % 100;
			if (b < c) b = c;
			s = s / 10;
			v[c] = v[c] + 1;
		}
	}
	for (int i = 10; i <= b; i++)
	{
		if (v[i] == 1) cout << i << " ";
	}
	cin.ignore();
	cin.get();
}