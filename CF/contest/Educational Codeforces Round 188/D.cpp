#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n, m;
	cin >> n >> m;
	vector <vector <int> > e(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	vector <int> val(n + 1, -1);
	int ans = 0;
	val[0] = 0;

	for (int i = 1; i <= n; i++) {
		if (val[i] != -1) continue;
		queue <int> q;
		q.push(i);
		val[i] = 0;
		int cnt[2] = {1, 0};
		bool ok = true;

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : e[u]) {
				if (val[v] == -1) {
					val[v] = val[u] ^ 1;
					cnt[val[v]]++;
					q.push(v);
				}else if (val[v] == val[u]) {
					ok = false;
				}
			}
		}
		if (ok) ans += max(cnt[0], cnt[1]);
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