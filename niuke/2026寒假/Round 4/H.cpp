#include <bits/stdc++.h>
using namespace std;
#define int long long

struct point {
    int x, y;
};

void solve ()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector <vector <int> > v(n + 5, vector <int> (m + 5));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j]; 
        }
    }

    vector <vector <int> > s(n + 5, vector <int> (m + 5, 0));
    int mx = -1;
    deque <point> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = v[i - 1][j] + v[i][j] + v[i + 1][j] + v[i][j - 1] + v[i][j + 1]
                    + v[i - 1][j - 1] + v[i - 1][j + 1] + v[i + 1][j - 1] + v[i + 1][j + 1];
            if (i > 2) s[i][j] += v[i - 2][j];
            if (j > 2) s[i][j] += v[i][j - 2];
            if (i < n - 1) s[i][j] += v[i + 2][j];
            if (j < m - 1) s[i][j] += v[i][j + 2];
            mx = max(mx, s[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == mx) {
                t.push_back({i, j});
            }
        }
    }

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        vector <point> l;
        s[x][y] += z;
        s[x][y - 1] += z;
        s[x][y + 1] += z;
        s[x + 1][y] += z;
        s[x + 1][y + 1] += z; 
        s[x + 1][y - 1] += z;
        s[x - 1][y] += z;
        s[x - 1][y + 1] += z;
        s[x - 1][y - 1] += z;
        if (x > 2) s[x - 2][y] += z;
        if (y > 2) s[x][y - 2] += z;
        if (x < n - 1) s[x + 2][y] += z;
        if (y < m - 1) s[x][y + 2] += z;

        mx = max({mx, s[x][y], s[x][y - 1], s[x][y + 1], s[x + 1][y], s[x + 1][y + 1], s[x + 1][y - 1], 
                  s[x - 1][y], s[x - 1][y + 1], s[x - 1][y - 1]});
        if (x > 2) mx = max(mx, s[x - 2][y]);
        if (y > 2) mx = max(mx, s[x][y - 2]);
        if (x < n - 1) mx = max(mx, s[x + 2][y]);
        if (y < m - 1) mx = max(mx, s[x][y + 2]);

        l.push_back({x, y});
        l.push_back({x, y - 1});
        l.push_back({x, y + 1});
        l.push_back({x + 1, y});
        l.push_back({x + 1, y + 1});
        l.push_back({x + 1, y - 1});
        l.push_back({x - 1, y});
        l.push_back({x - 1, y + 1});
        l.push_back({x - 1, y - 1});
        if (x > 2) l.push_back({x - 2, y});
        if (y > 2) l.push_back({x, y - 2});
        if (x < n - 1) l.push_back({x + 2, y});
        if (y < m - 1) l.push_back({x, y + 2});

        auto [h, k] = t.front();
        if (s[h][k] != mx) {
            while (t.size()) {
                t.pop_back();
            }
            for (int i = 0; i < l.size(); i++) {
                auto [p, q] = l[i];
                if (s[p][q] == mx) {
                    t.push_back({p, q});
                }
            }
        }else {
            for (int i = 0; i < l.size(); i++) {
                auto [p, q] = l[i];
                if (s[p][q] == mx) {
                    t.push_back({p, q});
                }
            }
        }
        auto [u, v] = t.front();
        cout << u << ' ' << v << '\n';
    }
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;   
    while (_--) {
        solve();
    }
    return 0;
} 

/*
  /\_/\
 (= ._.)
 / >  \>
*/