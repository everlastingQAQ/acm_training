#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;

void solve ()
{
    int sumh = 0;
    int summ = 0;

    for (int i = 0; i < 3; i++) {
        int h1, m1, h2, m2;
        cin >> h1 >> m1 >> h2 >> m2;
        sumh += h2 - h1;
        summ += m2 - m1;
    }

    if (summ < 0) {
        int t = 0 - summ;
        int temp = t / 60 + 1;
        sumh -= temp;
        summ += temp * 60;
    }else if (summ >= 60) {
        int t = summ / 60;
        sumh += t;
        summ -= t * 60;
    }

    cout << sumh << ' ' << summ << endl;
    if (sumh >= 4) {
        cout << "YES";
    }else {
        cout << "NO";
    }
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	//cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}