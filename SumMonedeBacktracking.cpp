#include <iostream>
#include <fstream>
using namespace std;
int P[30], V[30], M[30], S, n, NrSol, s;
void Plata(int);
int main()
{
	int i;
	ifstream f("summod.txt");
	f >> n >> S;
	for (i = 0; i < n; i++) f >> M[i];
	for (i = 0; i < n; i++) f >> V[i];
	Plata(0); cin.ignore();
	cin.get(); return 0;
}

void Afisare()
{
	cout << "Solutia nr. " << ++NrSol << endl;
	for (int i = 0; i < n; i++) cout << P[i] << " monede cu valoarea " << V[i] << endl;
	
}

void Plata(int k)
{
	int i;
	if (k == n)
	{
		if (s == S) Afisare();
	}
	else
	{
		for (i = 0; i <= M[k] && s + i * V[k] <= S; i++)
		{
			P[k] = i; s += i * V[k];
			Plata(k + 1);
			s -= i * V[k];
		}
			
	}
}