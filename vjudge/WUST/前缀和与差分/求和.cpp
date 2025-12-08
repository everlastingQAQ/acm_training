#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e6 + 2;

void solve ()
{
    int n;
    cin >> n;

    vector <int> a(n + 2);
    vector <int> sum(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }

    ll ans = 0;

    for (int i = 1; i < n; i++) {
        ans += 1LL * a[i] * (sum[n] - sum[i]);
    }

    cout << ans << endl;
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