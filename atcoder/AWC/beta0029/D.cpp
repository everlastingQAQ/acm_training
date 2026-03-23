#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n, m, k;
  	cin >> n >> m >> k;
  	vector <vector <array <int, 2> > > e(n + 1);
  	for (int i = 1; i <= m; i++) {
  		int u, v, w;
  		cin >> u >> v >> w;
  		if (w < k) continue;
  		e[u].push_back({v, 1});
  		e[v].push_back({u, 1});
  	}

  	vector <i64> dis(n + 1, 1e11);
  	priority_queue <array <int, 2>, vector <array <int, 2> >, greater<array <int, 2> > > pq;
  	pq.push({0, 1});
  	dis[1] = 0;

  	while (!pq.empty()) {
  		auto [dist, u] = pq.top();
  		pq.pop();
  		if (dist != dis[u]) continue;
  		for (auto [v, w] : e[u]) {
  			if (dis[v] > w + dis[u]) {
  				dis[v] = w + dis[u];
  				pq.push({dis[v], v});
  			}
  		}
  	}

  	cout << (dis[n] == 1e11 ? -1 : dis[n]) << '\n';
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