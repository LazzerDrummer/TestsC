#include <iostream>
#include <fstream>
using namespace std;
int *p; int v[10]; char fu[10]; char s[100]; int i, j;
void Rezolvare(int);
void Afisare();
int main()
{
	ifstream f("func.txt");
	f.getline(s, 100);
	char c;
	int a;
	while (!f.eof())
	{
		f >> c >> a;
		fu[i] = c; v[i++] = a;
	}
	f.close();
	i = 0;
	p = new int[strlen(s)];
	for (int i = 0; i < strlen(s); i++)
	{
		*(p + i) = 0;
	}
	Rezolvare(0);
	Afisare();
	delete[]p;
	cin.ignore();
	cin.get();
	return 0;
}

void Afisare()
{
	for (int i = 0; i < strlen(fu); i++)
	{
		if (v[i] > 0) 
		{ 
			cout << "nu exista"; 
			return; 
		}
	}
	for (int i = 0; i < strlen(s); i++)
	{
		cout << s[i];
		if (p[i] > 0)
		{
			while (p[i] > 0)
			{
				cout << ')'; p[i]--;
			}
			if (i < strlen(s) - 1) cout << ',';
		}
		else if (strchr(fu, s[i]) != NULL) cout << '(';
		else cout << ',';
	}
}

void Rezolvare(int n)
{
	while (v[n] && i < strlen(s) - 1)
	{
		i++;
		if (strchr(fu, s[i]) != NULL)
		{
			Rezolvare(++j);
		}
		v[n]--;
	}
	p[i]++;
}
