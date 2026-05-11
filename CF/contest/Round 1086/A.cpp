#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    map <int, int> mp;
    int x = n * (n - 1);
    bool ok = true;
    for (int i = 1; i <= n * n; i++) {
    	int t;
    	cin >> t;
    	mp[t]++;
    	if (mp[t] > x) {
    		ok = false;
    	}
    }
    cout << (ok ? "YES\n" : "NO\n");
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