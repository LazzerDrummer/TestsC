#include <iostream>

using namespace std;
int v[100];


void print_array(int n)
{
	for (int i = 1; i <= n; i++)
		cout << v[i];
	cout << endl;
}

void swap(int &a, int &b)
{
	int aux = a;
	a = b;
	b = aux;
}

void permutate(int start, int finish)
{
	if (start == finish)
	{
		print_array(finish);
		return;
	}
	for (int i = start; i <= finish; i++)
	{
		swap(v[start], v[i]);
		permutate(start + 1, finish);
		swap(v[start], v[i]);
	}
}

int main()
{
	int n; 
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	permutate(1, n);
	cin.ignore();
	cin.get();
}
