#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using ld = long double;

void solve ()
{
	int n;
	cin >> n;
	vector <array <int, 2> > v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i][0] >> v[i][1];
	}    
	vector <ld> dp(n + 2);
	for (int i = n; i >= 1; i--) {
		dp[i] = max(dp[i + 1], v[i][0] + dp[i + 1] * (1 - 1.0 * v[i][1] / 100));
	}

	cout << fixed << setprecision(10);
	cout << dp[1] << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 