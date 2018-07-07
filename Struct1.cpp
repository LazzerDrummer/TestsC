#include <iostream>

using namespace std;

struct masina
{
	struct data
	{
		int luna;
		int anul;
	}data;
	char marca[20];
}m;

int main()
{
	m.data.luna = 12;
	m.data.anul = 2012;
	cin.get(m.marca, 21);
	cout << m.data.luna << m.data.anul << m.marca;
	cin.ignore();
	cin.get();
}