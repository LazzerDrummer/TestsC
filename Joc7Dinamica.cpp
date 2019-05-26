#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
char A[150], B[150], C[300], s[300];
void Back(int a, int b, int k)
{
	if (k == strlen(A) + strlen(B)) return;
	if (C[k] == A[a] && a < strlen(A))
	{
		s[k] = 'A'; s[k + 1] = '\0';
		Back(a + 1, b, k + 1);
		if (strlen(s) == strlen(A) + strlen(B)) return;
		if (C[k] == B[b] && b < strlen(B))
		{
			s[k] = 'B'; s[k + 1] = '\0';
			Back(a, b + 1, k + 1);
			if (strlen(s) == strlen(A) + strlen(B)) return;
		}
	}
	else if(C[k] == B[b] && b < strlen(B))
	{
		s[k] = 'B'; s[k + 1] = '\0';
		Back(a, b + 1, k + 1);
		if (strlen(s) == strlen(A) + strlen(B)) return;
	}
}

int main()
{
	ifstream f("joc.txt");
	f.get(A, 150); f.ignore();
	f.get(B, 150); f.ignore();
	f.get(C, 300);
	f.close();
	Back(0, 0, 0);
	cout << s; cin.ignore();
	cin.get(); return 0;
}