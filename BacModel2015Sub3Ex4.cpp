#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
	int n, x, i, F[10] = {0};
	ifstream f("bac1.txt"); f >> n;
	while (f >> x)
	{
		i = 0;
		while (x >> 1) { i++; x = x >> 1; }
		F[i]++;
	}
	for (i = 0; i < 10; i++)
	{
		if (n <= F[i]) 
		{ 
			cout << (1 << i); 
			cin.ignore();
			cin.get();
			return 0; 
		}
		else n -= F[i];
	}
	cout << "Nu exista";
	cin.ignore();
	cin.get();
}