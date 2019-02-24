#include <iostream>
#include <fstream>
using namespace std;
unsigned long x; int n, lg; bool v[10];
void Cifre_Frecventa(); void Generare(int);
int main()
{
	ifstream f("gennum.txt");
	f >> n >> lg;
	Cifre_Frecventa();
	Generare(0); cin.ignore();
	cin.get(); return 0;
}

void Cifre_Frecventa()
{
	do
	{
		v[n % 10] = true;
		n /= 10;
	} while (n);
}

void Generare(int k)
{
	int i;
	if (k == lg) cout << x << '\n';
	else
	{
		for (i = x % 10; i <= 9; i++)
			if (v[i])
			{
				x = x * 10 + i;
				Generare(k + 1);
				x /= 10;
			}
	}
}
