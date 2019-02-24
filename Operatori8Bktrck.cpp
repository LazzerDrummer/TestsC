#include <iostream>
#include <fstream>
using namespace std;
int n, a[10], sumpar[10]; bool b[10]; int Sum;
void Generare(int);
void Sume_Partiale();
int main()
{
	ifstream f("op.txt");
	f >> n;
	for (int i = 0; i < n; i++) f >> a[i];
	Sume_Partiale();
	Sum += a[0];
	Generare(1); cin.ignore();
	cin.get(); return 0;
}

void Afisare()
{
	int i;
	for (i = 0; i < n - 1; i++)
	{
		cout << a[i];
		if (b[i + 1]) cout << "+";
		else cout << "-";
	}
	cout << a[i] << '\n';
}

void Sume_Partiale() 
{
	int s = 0;
	for (int i = n - 1; i > 0; i--)
	{
		s += a[i];
		sumpar[i] = s;
	}
}

void Generare(int k)
{
	if (k == n) Afisare();
	else
	{
		Sum += a[k];
		b[k] = true;
		Generare(k + 1);
		Sum -= a[k];
		if (Sum - a[k] + sumpar[k + 1] > 0)
		{
			Sum -= a[k];
			b[k] = false;
			Generare(k + 1);
			Sum += a[k]; //Necessary line!
		}
	}
}