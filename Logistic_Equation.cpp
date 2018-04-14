#include<iostream>

using namespace std;


int iteration = 99800;
double x0 = 0.7;
double r = 3.97;
int v[11];


void logistic_equation(double p0, double r, int iteration)
{
	double p;
	int index;
	for(int i = iteration;i>0;i--)
	{
		p0 = r * p0*(1 - p0);
		index = p0 * 10;
		v[index]++;
	}
	//cout << p << endl;
	//cout << count << endl;
}


int main()
{
	logistic_equation(x0, r, iteration);
	for(int i = 0; i < 10; i++)
		cout << v[i] << endl;
	cin.get();
}
