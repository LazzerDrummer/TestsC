#include <iostream>
#include <fstream>
using namespace std;
void ToatePerm(int *v, int n)
{
	for (int i = 1; i < n; i++)
	{
		cout << v[i] << ' ';
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				cout << v[j] << ' ';
			}
		}
		cout << endl;
	}
}

int main()
{
	int n; int v[20];
	ifstream f("perm.txt");
	f >> n;
	for (int i = 0; i < n; i++)
		f >> v[i];
	ToatePerm(v, n); 
}