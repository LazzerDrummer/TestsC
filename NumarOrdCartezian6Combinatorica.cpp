#include <iostream>
#include <fstream>
using namespace std;
int NrOrd(int *q, int *m, int **r, int n);
void Gen(int *q, int *m, int **p, int n, int mx, int k, int *a);
int ord = -1;
int main()
{
	ifstream f("nrord.txt"); int n,n1; bool b;
	f >> n;
	int **p = new int*[n];
	int **r = new int*[n];
	int *m = new int[n];
	int q[100] = {0};
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
	f >> b;
	f >> n1;
	if (!b)
	{
		int j; int mx=0;
		for (int i = 0; i < n1; i++)
		{
			f >> j; q[j]++;
			if (j > mx) mx = j;
		}
		int *a = new int[n];
		Gen(q, m, p, n, mx, 0, a);
	}
	else 
	{
		for (int i = 0; i < n1; i++)
		{
			for (int j = 0; j < n; j++)
				f >> q[j];
			cout << NrOrd(q, m, r, n) << '\n';
		}
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

void Gen(int *q, int *m, int **p, int n, int mx, int k, int *a)
{
	if (k == n)
	{
		if (q[++ord])
		{
			for (int i = 0; i < n; i++)
			{
				cout << a[i] << ' ';
			}
			cout << '\n';
		}
		return;
	}
	for (int i = 0; i < m[k]; i++)
	{
		a[k] = p[k][i];
		Gen(q, m, p, n, mx, k + 1, a);
		if (ord == mx) return;
	}
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