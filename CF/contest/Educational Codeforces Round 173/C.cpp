#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	vector <i64> v(n + 1);
  	int pos = n + 1;
  	for (int i = 1; i <= n; i++) {
  		cin >> v[i];
  		if (v[i] != -1 && v[i] != 1) {
  			pos = i;
  		}
  	}
  	vector <i64> dp1(n + 1), dp2(n + 1); 
  	i64 mx1 = 0, mn1 = 0;
  	for (int i = 1; i < pos; i++) {
  		dp1[i] = max(dp1[i - 1] + v[i], 0LL);
  		mx1 = max(mx1, dp1[i]);
  		dp2[i] = min(dp2[i - 1] + v[i], 0LL);
  		mn1 = min(mn1, dp2[i]);
  	}

  	set <i64> ans;
  	for (i64 i = mn1; i <= mx1; i++) {
  		ans.insert(i);
  	}
  	if (pos == n + 1) {
  		cout << ans.size() << '\n';
  		for (auto x : ans) {
  			cout << x << ' ';
  		}
  		cout << '\n';
  		return;
  	}

  	vector <i64> dp3(n + 1), dp4(n + 1);
  	i64 mx2 = 0, mn2 = 0;
  	for (int i = pos + 1; i <= n; i++) {
  		dp3[i] = max(dp3[i - 1] + v[i], 0LL);
  		mx2 = max(mx2, dp3[i]);
  		dp4[i] = min(dp4[i - 1] + v[i], 0LL);
  		mn2 = min(mn2, dp4[i]);
  	}

  	for (i64 i = mn2; i <= mx2; i++) {
  		ans.insert(i);
  	}

  	i64 mn3 = 0, mx3 = 0;
  	i64 cur = 0;
  	for (int i = pos - 1; i >= 1; i--) {
  		cur += v[i];
  		mn3 = min(mn3, cur);
  		mx3 = max(mx3, cur);
  	}

  	i64 mn4 = 0, mx4 = 0;
  	cur = 0;
  	for (int i = pos + 1; i <= n; i++) {
  		cur += v[i];
  		mn4 = min(mn4, cur);
  		mx4 = max(mx4, cur);
  	}
  	for (i64 i = mn3 + mn4; i <= mx3 + mx4; i++) {
  		ans.insert(v[pos] + i);
  	}

  	cout << ans.size() << '\n';
  	for (auto x : ans) {
  		cout << x << ' ';
  	}
  	cout << '\n';
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