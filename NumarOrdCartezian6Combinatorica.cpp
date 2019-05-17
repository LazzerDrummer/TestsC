#include <iostream>
#include <fstream>
using namespace std;
int NrOrd(int *q, int *m, int **r, int n);
int main()
{
	ifstream f("nrord.txt"); int n,n1;
	f >> n;
	int **p = new int*[n];
	int **r = new int*[n];
	int *m = new int[n];
	int *q = new int[n];
	for (int i = 0; i < n; i++)
	{
		f >> m[i];
		p[i] = new int[m[i]];
		r[i] = new int[100];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m[i]; j++)
		{
			f >> p[i][j];
			r[i][p[i][j]] = j;
		}
	}
	f >> n1;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n; j++)
			f >> q[j];
		cout << NrOrd(q, m, r, n) << '\n';
	}
	for (int i = 0; i < n; i++)
	{
		delete[] p[i];
		delete[] r[i];
	}
	delete[] p;
	delete[] r;
	delete[] m;
	delete[] q;
	cin.ignore();
	cin.get(); return 0;
}

int NrOrd(int *q, int *m, int **r, int n)
{
	int nrord = 0;
	int l;
	for (int i = 0; i < n; i++)
	{
		l = r[i][q[i]];
		for (int j = i + 1; j < n; j++)
		{
			l *= m[j];
		}
		nrord += l;
	}

	return nrord;
}