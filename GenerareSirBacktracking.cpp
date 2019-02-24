#include <iostream>
#include <fstream>
#include <math.h>
#define NMax 11
using namespace std;
int s[NMax]; int n, lg; int D;
void Generare(int);
int main()
{
	ifstream f("gensir.txt");
	f >> n >> lg >> D;
	s[0] = n;
	Generare(1); cin.ignore();
	cin.get(); return 0;
}

void Afisare()
{
	for (int i = 0; i < lg; i++) cout << s[i] << ' ';
	cout << '\n';
}

void Generare(int k)
{
	int i = 1;
	if (k == lg) Afisare();
	else
	{
		int steps = D*(lg - k - 1);
		if (s[k - 1] - D > 1) i = s[k - 1] - D;
		if (i < n - steps) i = n - steps;
		for (i; i >= n - steps && i <= n + steps && i <= s[k - 1] + D; i++)
		{
			s[k] = i;
			Generare(k + 1);
		}
		/*int steps = lg - k - 1;
		if (s[k - 1] + 1 <= n + steps)
		{
			s[k] = s[k - 1] + 1;
			Generare(k + 1);
		}
		//s[k] = 0; This line is useless.
		if (s[k - 1] - 1 > 0)
			if (s[k - 1] - 1 >= n - steps)
			{
				s[k] = s[k - 1] - 1;
				Generare(k + 1);
			}

		//s[k] = 0; This line is also... useless.
		*/
	}
}