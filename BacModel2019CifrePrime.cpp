#include <iostream>

using namespace std;

int CifrePrime(int n)
{
	int k, s = 0;
	while (n > 0) {
		k = n % 10; n /= 10;
		if (k == 4 || k == 6 || k == 8 || k == 9 || k==1) continue;
		s += k;
	} return s;
}

int main() 
{
	cout << CifrePrime(1235405) << ' ' << CifrePrime(140);
	cin.ignore();
	cin.get();
}