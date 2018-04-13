#include<iostream>

using namespace std;


int iteration = 998;
double x0 = 0.02;
double r = 3.98934;
int v[11];


int logistic_equation(double p0, double r, int iteration, int count, double range)
{
	if (iteration == 0) return count;
	iteration--;
	double p;
	p = r * p0*(1 - p0);
	if (p < range + 0.1 && p > range) count++;
	//cout << p << endl;
	//cout << count << endl;
	logistic_equation(p, r, iteration, count, range);
}


int main()
{
	for (double i = 0; i < 10; i++)
		cout << logistic_equation(x0, r, iteration, 0, i/10) << endl;
	cin.get();
}
