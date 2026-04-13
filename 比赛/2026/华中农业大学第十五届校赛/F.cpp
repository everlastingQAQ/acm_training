#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
	cin >> n;
	vector <array <int, 2> > v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i][0] >> v[i][1];
	}

	vector <int> ans;
	auto dfs = [&] (auto self, int fa, int u) -> void {
		ans.push_back(u);
		if (v[u][0] != 0) self(self, u, v[u][0]);
		ans.push_back(u);
		if (v[u][1] != 0) self(self, u, v[u][1]);
	};
	dfs(dfs, 0, 1);
	
	vector <int> cnt(n + 1);
	string s;
	for (auto x : ans) {
		if (cnt[x] == 0) {
			s.push_back('(');
			cnt[x]++;
		}else {
			s.push_back(')');
		}
	}
	
	cout << s << '\n';
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
