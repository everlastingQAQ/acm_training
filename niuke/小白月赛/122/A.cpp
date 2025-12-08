#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
const double eps = 1e-5;
int a[7];
int b[7];
int x, y;

void solve ()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    for (int i = 1; i <= 6; i++) {
        int t;
        cin >> t;
        a[t]++;
    }

    for (int i = 1; i <= 6; i++) {
        int t;
        cin >> t;
        b[t]++;
    }

    cin >> x >> y;

    if (a[y] + b[y] < x) {
        cout << "win" << endl;
    }else {
        cout << "lose" << endl;
    }

}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _ = 1;
	cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}