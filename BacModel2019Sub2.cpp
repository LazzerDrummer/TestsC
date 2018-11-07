#include <iostream>

using namespace std;

int main()
{
	int n,k,i;
	cin >> n;
	k = 1;
	for(k=1;n>=1;k++)
	{
		if (n > k) i = k;
		else i = n;
		n = n - i;
		while (i >= 1)
		{
			cout << k << ' '; i--;
		}
	}
	cin.ignore();
	cin.get();
}