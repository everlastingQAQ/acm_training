#include <bits/stdc++.h>
using namespace std;
#define int long long

struct point {
    int x, y;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector <vector <int> > vis(n + 1, vector <int> (m + 1, 0));
    priority_queue <array <int, 3>, vector<array <int, 3> >, greater<array<int, 3> > > q;
    int cnt = 0;
    for (int i = 1; i <= a; i++) {
        int x, y;
        cin >> x >> y;
        vis[x][y] = 1;
        q.push({0, x, y});
        cnt++;
    }
    
    int ans = 0;
    
    map <array <int, 2> , int> mp1;
    for (int i = 1; i <= b; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        ans = max(ans, t);
        vis[x][y] = -1;
        mp1[{x, y}] = t;
    }
    
    vector <int> v(n * m + 10000, 0);
    
    while (q.size()) {
        auto [t, x, y] = q.top();
        q.pop();

        ans = max(ans, t);
        
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if (vis[xx][yy] == 1) continue;
            q.push({max(t + 1, mp1[{xx, yy}]), xx, yy});
            vis[xx][yy] = 1;
        }
    }

    cout << ans << '\n';

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