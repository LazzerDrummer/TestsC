#include <iostream>
#include <fstream>
using namespace std;
int A[20][20]; int n; int q[50]; int G[20]; int d[20];

bool BreadthBipartit()
{
	int i = 0;
	int k = 1;
	G[q[i]] = 1;
	while (q[i] != 0)
	{
		for (int j = 1; j <= A[q[i]][0]; j++)
		{
			if (!G[A[q[i]][j]])
			{
				q[k] = A[q[i]][j];
				G[q[k]] = 3 - G[q[i]];
				k++;
			}
			else
				if (G[A[q[i]][j]] != 3 - G[q[i]]) return false;
		}
		i++;
	}
	return true;
}

int HasZero(int &i)
{
	for (i = 1; i <= n; i++)
	{
		if (G[i] == 0) return i;
	}
	return 0;
}


int main()
{
	bool b; int z;
	ifstream f("bipartit.txt");
	f >> n;
	for (int i = 1; i <= n; i++)
	{
		f >> A[i][0];
		for (int j = 1; j <= A[i][0]; j++)
			f >> A[i][j];
	}
	int i = 0;
	q[0] = 1;
	f.close();
	if (!BreadthBipartit()) { cout << "nu e"; cin.ignore(); cin.ignore(); return 0; }
	while (HasZero(z))
	{
		while (q[i]) q[i++] = 0;
		q[0] = z;
		if (!BreadthBipartit()) { cout << "nu e"; cin.ignore(); cin.ignore(); return 0; }
	}
	cout << "este"; cin.ignore();
	cin.ignore(); return 0;
}
