#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
int a[MAXN];
int n, k;

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    int n;
    cin >> n;

    int mx;
    cin >> mx;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    cout << mx << endl;

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