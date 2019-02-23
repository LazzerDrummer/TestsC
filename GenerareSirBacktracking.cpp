#include <iostream>
#include <fstream>
#include <math.h>
#define NMax 11
using namespace std;
int s[NMax]; int n, lg; long nrsol;
void Generare(int);
int main()
{
	int i;
	ifstream f("gensir.txt");
	f >> n >> lg;
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
	if (k == lg) Afisare();
	else
	{
		int steps = lg - k - 1;
		if (s[k - 1] + 1 <= n + steps)
		{
			s[k] = s[k - 1] + 1;
			Generare(k + 1);
		}
		s[k] = 0;
		if (s[k - 1] - 1 > 0)
			if (s[k - 1] - 1 >= n - steps)
			{
				s[k] = s[k - 1] - 1;
				Generare(k + 1);
			}

		//s[k] = 0; This line is useless.
	}
}