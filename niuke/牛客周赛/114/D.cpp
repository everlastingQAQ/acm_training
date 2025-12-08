#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
const double eps = 1e-5;
int n;

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> n;

    int a[MAXN];
    memset(a, 0, sizeof(a));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[1] << endl;
    }

    int dp[MAXN];
    memset(dp, 0, sizeof(dp));

    dp[1] = a[1];

    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }

    cout << dp[n] << endl;
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