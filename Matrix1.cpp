#include <iostream>

using namespace std;

int main()
{
	int n, v[50][50];
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (abs(((i+j) - (n - 1))) <= 1) v[i][j] = 1;
			else v[i][j] = 2;
		}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cout << v[i][j] << ' ';
		cout << endl;
	}
	cin.ignore();
	cin.get();
}