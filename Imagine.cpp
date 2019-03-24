#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
char r[256]; int **p;
int Compresie(int, int, int, int, int);
int main()
{
	int n;
	ifstream f("imagine.in");
	ofstream g("imagine.out");
	f >> n;
	p = new int*[n];
	for (int i = 0; i < n; i++) p[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			f >> p[i][j];
	f.close();
	Compresie(0, 0, n - 1, n - 1, -1);
	for (int i = 0; i < n; i++) delete p[i];
	delete[]p;
	g << strlen(r) << '\n';
	g << r;
	g.close();
}


int Compresie(int x0, int y0, int x1, int y1, int bg)
{
	if (x0 == x1 && y0 == y1)
	{
		if (p[y0][x0] == 1)
		{
			strcat(r, "01");
			return 1;
		}
		else
		{
			strcat(r, "00");
			return 0;
		}
	}
	int a, b, c, d;
	int halfx = (x0 + x1) / 2, halfy = (y0 + y1) / 2;
	strcat(r, "1");
	a = Compresie(x0, halfy + 1, halfx, y1, (int) strlen(r) - 1);
	b = Compresie(x0, y0, halfx, halfy, (int) strlen(r) - 1);
	c = Compresie(halfx + 1, halfy + 1, x1, y1, (int) strlen(r) - 1);
	d = Compresie(halfx + 1, y0, x1, halfy, (int) strlen(r) - 1);
	if (a == b && b == c && c == d && d == 1)
	{
		r[bg + 1] = '\0'; 
		strcat(r, "01");
		return 1;
	}
	if (a == b && b == c && c == d && d == 0)
	{
		r[bg + 1] = '\0';
		strcat(r, "00");
		return 0;
	}
	return 2;
}