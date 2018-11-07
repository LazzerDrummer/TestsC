#include <iostream>

using namespace std;

struct complex
{
	double pre;
	double pim;
}z[20];

int main()
{
	z[0].pre = 2;
	z[0].pim = 3;
	cout << z[0].pre + z[0].pim;
	cin.ignore();
	cin.get();
}