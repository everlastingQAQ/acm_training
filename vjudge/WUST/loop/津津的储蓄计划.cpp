#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int money = 0;
	int saving = 0;
	for (int i = 1; i <= 12; i++) {
		money += 300;
		int budget;
		cin >> budget;
		money -= budget;
		if (money < 0) {
			cout << -i;
			return 0;
		}else {
			saving += money - money % 100;
			money -= money - money % 100;
		}
	}
	money += saving * 1.2;
	
	cout << money;
	
	return 0;
}
