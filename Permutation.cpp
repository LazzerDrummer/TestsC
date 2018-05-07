#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
int v[100];
string s[100000];
//char z[1000];
int len = 0;

void save_array(int n)
{
	len++;
	int number = 0;
	//char str[1000];
	for (int i = 1; i <= n; i++)
		number = number * 10 + v[i];
		//str[i] = z[v[i]];
	stringstream ss;
	ss << number;
	string str = ss.str();
	s[len] = str;
		
}

void swap(int &a, int &b)
{
	int aux = a;
	a = b;
	b = aux;
}

bool condition(int v[100], int n, int number1, int number2)
{
	int index1 = 0;
	int index2 = 0;
	int i = 1;
	while (index1 == 0 && index2 == 0)
	{
		if (i > n) return false;
		if (v[i] == number1)index1 = i;
		if (v[i] == number2)index2 = i;
		i++;
	}
	if (index1 > index2) return true;
	else return false;
}

void permutate(int start, int finish)
{
	if (start == finish)
	{
		if (condition(v, finish, 2, 3)) save_array(finish);
		//save_array(finish);
		return;
	}
	for (int i = start; i <= finish; i++)
	{
		swap(v[start], v[i]);
		permutate(start + 1, finish);
		swap(v[start], v[i]);
	}
}

int main()
{
	int n; 
	cin >> n;
	for (int i = 1; i <= n; i++)
			v[i] = i;
	//cin.get(z, 1001);
	permutate(1, n);
	sort(s, s + len + 1);
	for (int i = 1; i <= len; i++)
	{
		cout << s[i];
		cout << '\n';
	}	
	cin.ignore();
	cin.get();
}
