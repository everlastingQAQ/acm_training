#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e6 + 2;

void solve ()
{
    int n, p;
    cin >> n >> p;

    vector <int> a(n + 2);
    vector <int> b(n + 2);
    vector <int> d(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }

    for (int i = 0; i < p; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x] += z;
        d[y + 1] -= z;
    }

    int mn = 101;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + d[i];
        mn = min(mn, a[i]);
    }

    cout << mn << endl;

}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _ = 1;
	//cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}