#include <iostream>
#include <fstream>
using namespace std;
unsigned long x; int S, Sum; bool v[10];
void Generare(int);
int main()
{
	ifstream f("sumcifre.txt");
	f >> S;
	Generare(0); cin.ignore();
	cin.get(); return 0;
}

void Generare(int k)
{
	if (Sum == S) cout << x << '\n';
	int i = 0;
	if (k == 0) i = 1;
	for (i; i < 10; i++)
		if (!v[i] && Sum + i <= S)
		{
			x = x * 10 + i;
			v[i] = true;
			Sum += i;
			Generare(k + 1);
			v[i] = false;
			Sum -= i;
			x /= 10;
		}
}