#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
	cin >> n;
	vector <int> v(n + 1), pre(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		pre[i] = max(pre[i - 1], v[i]);
	}

	int ans = 0;
	for (int i = n; i >= 1; i--) {
		if (v[i] == pre[i]) {
			ans++;
		}
	}
	cout << ans << '\n';
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