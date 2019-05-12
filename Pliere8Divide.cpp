#include <iostream>
using namespace std;
char sol[100];

void Divide(int *p, char *s, int &x, int &y)
{
	if (x == y) return;
	int p1[50], p2[50], r1[50], r2[50];
	char s1[100] = ""; 
	char s2[100] = "";
	int x1, y1, x2, y2;
	int m = (y - x) + 1;
	int n = m / 2;
	for (int i = 0; i < n; i++)
	{
		p1[i] = p[i];
		p2[i] = p[m - 1 - i];
	}
	x1 = x; y2 = y;
	if (m % 2 == 0)
	{
		y1 = (x + y) / 2;
		x2 = y1 + 1;
	}
	else 
	{ 
		y1 = (x + y) / 2 - 1;
		x2 = y1 + 2;
	}
	for (int i = 0; i < n; i++)
	{
		r1[i] = 2 * p1[i] - p2[i];
		r2[i] = 2 * p2[n - 1 - i] - p1[n - 1 - i];
	}
	int aux1 = y1;
	int aux2 = x2;
	Divide(r1, s1, x1, y1);
	Divide(r2, s2, x2, y2);
	if (r1[0] == 0 && x1==y1)
	{
		strcpy(s, "S");
		char c[5];
		c[0] = 48 + aux1; c[1] = ' '; c[2] = '\0';
		strcat(s, c);
		strcat(s, s1);
		p[0] = r1[0]; x = x1; y = y1;
	}
	if (r2[0] == 0 && x2==y2)
	{
		strcpy(s, "D");
		char c[5];
		c[0] = 48 + aux2; c[1] = ' '; c[2] = '\0';
		strcat(s, c);
		strcat(s, s2);
		p[0] = r2[0]; x = x2; y = y2;
	}
}

int main()
{
	int v[10] = { 10,-10,320,40,50 };
	int x = 1; int y = 5;
	Divide(v, sol, x, y);
	cout << sol; cin.ignore();
	cin.get(); return 0;
}