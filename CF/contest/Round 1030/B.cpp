#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    cout << 2 * n - 1 << '\n';
    for (int i = 1; i <= n; i++) {
    	cout << i << ' ' << 1 << ' ' << i << '\n';
    	if (i != n) cout << i << ' ' << i + 1 << ' ' << n << '\n';
    }
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