#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <i64> > v(n + 1, vector <i64> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    i64 ans1 = 0;
    int t = 0;
    for (int i = 30; i >= 0; i--) {
        if (((v[1][1] >> i) & 1) || ((v[1][1] & t) != 0)) {
            ans1 += (1LL << i);
            continue;
        }

        vector <vector <int> > vis(n + 1, vector <int> (m + 1, 0));
        queue <array <int, 2> > q;
        q.push({1, 1});
        vis[1][1] = true;
        bool ok = false;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n && y == m) {
                ok = true;
                break;
            }
            for (int j = 0; j < 4; j++) {
                int xx = x + dx[j];
                int yy = y + dy[j];
                if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
                if (vis[xx][yy]) continue;
                vis[xx][yy] = true;
                if (((v[xx][yy] >> i) & 1) || (v[xx][yy] & t) != 0) continue;
                q.push({xx, yy});
            }
        }
        if (!ok) {
            ans1 += (1LL << i);
        }else {
            t |= (1LL << i);
        }
    }

    i64 ans2 = 0;
    i64 x = 0;

    for (int i = 30; i >= 0; i--) {
        if (((ans1 >> i) & 1) == 0) continue;
        i64 a = x | (1LL << i);
        if ((v[1][1] & t) != 0 || (v[1][1] & a) != a) continue;

        vector <vector <int> > vis(n + 1, vector <int> (m + 1, 0));
        queue <array <int, 2> > q;
        q.push({1, 1});
        vis[1][1] = true;
        bool ok = false;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n && y == m) {
                ok = true;
                break;
            }
            for (int j = 0; j < 4; j++) {
                int xx = x + dx[j];
                int yy = y + dy[j];
                if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
                if (vis[xx][yy]) continue;
                vis[xx][yy] = true;
                if ((v[xx][yy] & t) != 0 || (v[xx][yy] & a) != a) continue;
                q.push({xx, yy});
            }
        }

        if (ok) {
            ans2 |= (1LL << i);
            x |= (1LL << i);
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';
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
