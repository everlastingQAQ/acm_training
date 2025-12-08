#include <bits/stdc++.h>
using namespace std;

int square (int n)
{
	return n * n;
}

int main ()
{
	int a, b, c;
	cin >> a >> b >> c;
	if(a > b) swap(a, b);
	if(a > c) swap(a, c);
	if(b > c) swap(b, c); 
	if (a + b <= c) {
		printf("Not triangle\n");
		return 0;
	}
	
	if (square(a) + square(b) == square(c)) {
		printf("Right triangle\n");
	}else if (square(a) + square(b) > square(c)) {
		printf("Acute triangle\n");
	}else if (square(a) + square(b) < square(c)) {
		printf("Obtuse triangle\n");
	}
	
	if (a == b || a == c || b == c) {
		printf("Isosceles triangle\n");
	}
	if (a == b && a == c) {
		printf("Equilateral triangle\n");
	}
	
	return 0;
	
}
