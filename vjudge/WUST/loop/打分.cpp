#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int max, min;
	int sum = 0;
	cin >> max;
	min = max;
	sum = max;
	
	for (int i = 1; i < n; i++) {
		int score;
		cin >> score;
		sum += score;
		if (score > max) {
			max = score; 
		}else if (score < min) {
			min = score;
		}
	}
	
	sum -= max + min;
	
	double average = 1.0 * sum / (n - 2);
	
	printf("%.2f", average);
	
	return 0;
	
}
