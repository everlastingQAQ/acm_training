#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	vector <int> a(n + 1), b(n + 1);
  	for (int i = 1; i <= n; i++) {
  		cin >> a[i];
  	}  
  	for (int i = 1; i <= n; i++) {
  		cin >> b[i];
  	}

  	int ans = 0;
  	vector <int> vis(n + 1);
  	if (a[n] == b[n]) {
  		cout << n << '\n';
  		return;
  	}

  	for (int i = n - 1; i >= 1; i--) {
  		if (vis[a[i]] || vis[b[i]]) {
  			ans = max(ans, i);
  		}
  		vis[a[i + 1]] = true;
  		vis[b[i + 1]] = true;
  		if (a[i] == b[i]) {
  			ans = max(ans, i);
  		}
  		if (a[i] == a[i + 1] || b[i] == b[i + 1]) {
  			ans = max(ans, i);
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