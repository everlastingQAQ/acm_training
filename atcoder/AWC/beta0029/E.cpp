#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	i64 n, m;
	cin >> n >> m;
	vector <vector <i64> > dis(n + 1, vector <i64>(n + 1, 1e14));
	for (int i = 1; i <= m; i++) {
		i64 u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = min(dis[u][v], w);
	}
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	int s, k;
	cin >> s >> k;
	vector <int> a(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	int N = 1 << k;

	vector <vector <i64> > dp(N, vector <i64> (k, 1e14));

	for (int i = 0; i < k; i++) {
		if (dis[s][a[i]] != 1e14) {
			dp[1 << i][i] = dis[s][a[i]];
		}
	}

	for (int mask = 0; mask < N; mask++) {
		for (int i = 0; i < k; i++) {
			if (!(mask & (1 << i)) || dp[mask][i] == 1e14) continue;
			for (int j = 0; j < k; j++) {
				if (mask & (1 << j) || dis[a[i]][a[j]] == 1e14) continue;
				dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + dis[a[i]][a[j]]);
			}
		}
	}

	i64 ans = 1e14;
	for (int i = 0; i < k; i++) {
		if (dp[N - 1][i] == 1e14) continue;
		if (dis[a[i]][s] == 1e14) continue;
		ans = min(ans, dp[N - 1][i] + dis[a[i]][s]);
	}

	cout << (ans == 1e14 ? -1 : ans) << '\n';
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