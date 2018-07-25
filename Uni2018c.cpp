#include <iostream>
#include <fstream>
#include <string.h>
#include  <vector>
#include <map>

using namespace std;

int main()
{
	int l, n, i, M = 0;
	cin >> l >> n;
	ifstream f("rau.txt");
	//vector<char> s;
	char s[100000];
	f.getline(s, l + 1); map<int, int> r1, r2;
	for (i = 0; i <strlen(s); i++)
		if (s[i] == ' ') r1[i] = 1;
	for (int j = 2; j <= n; j++)
	{
		f.getline(s, 100000);
		for (i = 0; i <strlen(s); i++)
		{
			if (s[i] == ' ')
			{
				int m = 0;
				for (int o = 1; o <= 3; o++)
				{
					if (r1.count(i - 2 + o))
					{
						if (m < r1[i - 2 + o]) m = r1[i - 2 + o];
					}
				}
				r2[i] = 1 + m;
				if (M < 1 + m) M = m + 1;
			}
		}
		r1.clear();
		r1.insert(r2.begin(), r2.end());
		r2.clear();
	}
	if (M < 2)cout << "NU";
	else cout << M;
	cin.ignore();
	cin.get();
}
