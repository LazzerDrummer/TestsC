#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int x, y;
	cin >> x >> y;
	ofstream g("bac.txt");
	while (x <= y)
	{
		g << y << ' ';
		if (y % 2 == 0) y--;
		else { y++; y = y >> 1; }
	}
	return 0;
}