#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	vector <vector <int> > e(n + 1);
  	vector <int> ind(n + 1, 0);
  	for (int i = 1; i < n; i++) {
  		int u, v;
  		cin >> u >> v;
  		e[u].push_back(v);
  		e[v].push_back(u);
  		ind[u]++;
  		ind[v]++;
  	}  

  	vector <int> vis(n + 1, 0);
  	vector <int> cnt(n + 1, 0);
  	queue <int> q;

  	for (int i = 1; i <= n; i++) {
  		if (i != 1 && ind[i] == 1) {
  			q.push(i);
  		}
  	}

  	while (!q.empty()) {
  		int v = q.front();
  		q.pop();
  		if (vis[v]) continue;
  		vis[v] = true;
  		for (auto u : e[v]) {
  			if (vis[u]) continue;
  			if (++cnt[u] >= 2) {
  				q.push(u);
  			}
  		}
  	}

  	for (auto v : e[1]) {
  		if (vis[v]) {
  			cout << "red\n";
  			return;
  		}
  	}

  	cout << "purple\n";
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