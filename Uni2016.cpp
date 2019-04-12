#include <iostream>
#include <fstream>
using namespace std; 
const int N = 100;
int p[N][N]; int fr[N]; bool s[N];
bool v[N];
int main()
{
	ifstream f("info.txt"); int n, m, k, i, j;
	f >> n >> m >> k;
	while (f >> i)
	{
		f >> j;
		p[i][fr[i]] = j; fr[i]++;
		p[j][fr[j]] = i; fr[j]++;
	}
	for (i = 1; i <= n; i++) cout << fr[i] << " ";
	cout << "\n";
	int queue[N]; 
	for (i = 0; i < n; i++) queue[i] = i + 1;
	i = 0; int l = n;
	while (l > i)
	{
		int q = queue[i];
		if (fr[q] < k) 
		{
			s[q] = true; j = -1;
			do
			{
				j++;
				int P = p[q][j];
				if (s[P]) continue;
				fr[P]--;
				if (!v[P]) continue;
				queue[l] = P; l++; v[P] = false;
			} while (p[q][j + 1] != 0);
		}
		i++; v[q] = true;
	}
	bool ok = true;
	for (i = 1; i <= n; i++)
		if (!s[i]) { cout << i << " "; ok = false; }
	if (ok) cout << "NU";
	cin.ignore(); cin.get(); return 0;
}