#include <bits/stdc++.h>
using namespace std;
const int MaxN = 11;
int n;

bool is_the_same (char a[][MaxN], char b[][MaxN])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != b[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void turn_90_degrees (char a[][MaxN], char b[][MaxN]) // 顺时针
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[j][n - 1 - i] = a[i][j];
		}
	}
}

void turn_180_degrees (char a[][MaxN], char b[][MaxN]) // 顺时针
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[n - 1 - i][n - 1 - j] = a[i][j];
		}
	}
}

void turn_270_degrees (char a[][MaxN], char b[][MaxN]) // 顺时针
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[n - 1 - j][i] = a[i][j];
		}
	}
}


void reverse (char a[][MaxN], char b[][MaxN]) // 水平翻转
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][n - 1 - j] = a[i][j];
		}
	}
}

int main ()
{
	cin >> n;
	
	char a[n][MaxN];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	char b[n][MaxN];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
	}
	
	char c[n][MaxN];
	turn_90_degrees(a, c);
	if (is_the_same(b, c) == true) {
		cout << 1;
		return 0;
	}
	
	turn_180_degrees(a, c);
	if (is_the_same(b, c) == true) {
		cout << 2;
		return 0;
	}
	
	turn_270_degrees(a, c);
	if (is_the_same(b, c) == true) {
		cout << 3;
		return 0;
	}
	
	reverse(a, c);
	if (is_the_same(b, c) == true) {
		cout << 4;
		return 0;
	}
	
	char d[n][MaxN];
	turn_90_degrees(c, d);
	if (is_the_same(b, d) == true) {
		cout << 5;
		return 0;
	}
	
	turn_180_degrees(c, d);
	if (is_the_same(b, d) == true) {
		cout << 5;
		return 0;
	}
	
	turn_270_degrees(c, d);
	if (is_the_same(b, d) == true) {
		cout << 5;
		return 0;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = a[i][j];
		}
	}
	if (is_the_same(b, c) == true) {
		cout << 6;
		return 0;
	}
	
	cout << 7;
	return 0;
}
