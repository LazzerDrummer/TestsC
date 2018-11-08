#include <iostream>
#include <string.h>

using namespace std;

char f[4];
int main() 
{
	char s[100]; int i = 0;
	cin.get(s, 101); int ok = 0;
	while (s[i] != ' ') 
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			i++; continue;
		}
		//strncat_s(f, &s[i], 1); ok++; i++;
		f[0] = s[i]; 
		ok++; i++; break;
	}
	while (s[i] != ' ') i++;
	while (s[i] == ' ') i++;
	while (s[i] != ' ')
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			//strncat_s(f, &s[i], 1); ok++;
			f[1] = s[i]; 
			ok++; i++; break;
		} i++;
	}
	if (ok != 2) {cout << "nu exista"; cin.ignore(); cin.get(); return 0;}
	//strncat_s(f, &s[strlen(s) - 1], 1);
	f[2] = s[strlen(s) - 1];
	printf("%s", f);
	cin.ignore();
	cin.get();
}