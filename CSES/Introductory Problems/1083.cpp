#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	map <int, int> mp;
  	for (int i = 1; i < n; i++) {
  		int t;
  		cin >> t;
  		mp[t] = 1;
  	}

    for (int i = 1; i <= n; i++) {
        if (!mp[i]) {
            cout << i << '\n';
            return;
        }
    }
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 