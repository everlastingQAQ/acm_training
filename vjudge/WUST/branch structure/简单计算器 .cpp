#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b;
	char c;
	cin >> a >> b >> c;
	if (c != '+' && c != '-' && c != '*' && c != '/') {
		printf("Invalid operator!");
		return 0;
	}
	if (c == '+') cout << a + b;
	if (c == '-') cout << a - b;
	if (c == '*') cout << a * b;
	if (c == '/' && b == 0) {
		printf("Divided by zero!");
		return 0;
	}
	if (c == '/') cout << a / b;
	return 0;
} 
