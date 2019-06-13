#include <iostream>
#include <fstream>
using namespace std;
int A[20][20]; bool viz[20]; int n; int q[50]; int vt[20]; int d[20];

void Breadth()
{
	int i = 0;
	int k = 1;
	viz[q[i]] = 1;
	//cout << q[i] <<' ';
	while (q[i] != 0)
	{
		for (int j = 1; j <= A[q[i]][0]; j++)
		{
			if (!viz[A[q[i]][j]])
			{
				q[k] = A[q[i]][j];
				viz[q[k]] = 1;
				vt[q[k]] = q[i];
				//cout << q[k] << ' ';
				k++;
			}
		}
		i++;
	}
}

void Drum(int end)
{
	int i = 0;
	d[0] = end;
	while (vt[d[i++]] != 0) 
		d[i] = vt[d[i - 1]];
	i--;
	for (i; i >= 0; i--)
	{
		cout << d[i] << ' ';
	}
}

int main()
{
	int end;
	ifstream f("breadth.txt");
	f >> n;
	for (int i = 1; i <= n; i++)
	{
		f >> A[i][0];
		for (int j = 1; j <= A[i][0]; j++)
			f >> A[i][j];
	}
	f >> q[0];
	f >> end;
	f.close();
	Breadth(); 
	Drum(end); cin.ignore();
	cin.get(); return 0;
}
