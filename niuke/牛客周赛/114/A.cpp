#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 4;
const double eps = 1e-5;

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    int t1, t2, t3;
    for (int i = 1; i <= 3; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            t1 = i;
        }
        if (t == 2) {
            t2 = i;
        }
        if (t == 3) {
            t3 = i;
        }
    }

    cout << t1 << ' ' << t2 << ' ' << t3;

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