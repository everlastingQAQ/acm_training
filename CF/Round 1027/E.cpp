#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	vector <i64> val(n + 1);
  	for (int i = 1; i <= n; i++) {
  		cin >> val[i];
  	}  
  	vector <vector <int> > e(n + 1);
  	for (int i = 1; i < n; i++) {
  		int u, v;
  		cin >> u >> v;
  		e[u].push_back(v);
  		e[v].push_back(u);
  	}
  	vector <array <i64, 2> > ans(n + 1);

  	auto dfs = [&] (auto self, int u, int fa) -> void {
  		ans[u][0] = max(ans[u][0], val[u] - ans[fa][1]);
  		ans[u][1] = min(ans[u][1], val[u] - ans[fa][0]);
  		for (auto v : e[u]) {
  			if (v == fa) continue;
  			self(self, v, u);
  		}
  	};
  	dfs(dfs, 1, 0);

  	for (int i = 1; i <= n; i++) {
  		cout << ans[i][0] << " \n"[i == n];
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