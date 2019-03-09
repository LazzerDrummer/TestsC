#include <iostream>
#include <fstream>
using namespace std;
int n, t; int v[20];
void Afisare(int);
void Generare(int);
int main()
{
	ifstream f("gensir12.txt");
	f >> n >> t;
	v[0] = n;
	Generare(1); cin.ignore();
	cin.get(); return 0;
}

void Afisare(int k)
{
	for (int i = 0; i < k; i++)cout << v[i] << ' ';
	cout << '\n';
}

void Generare(int k)
{
	if (v[k - 1] == n + t) Afisare(k);
	else
	{
		for (int i = v[k - 1] + 1; i <= n + t; i++)
		{
			v[k] = i;
			Generare(k + 1);
		}
	}
}