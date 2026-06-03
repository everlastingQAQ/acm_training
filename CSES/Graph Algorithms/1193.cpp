#include <bits/stdc++.h>
using namespace std;
#define int long long

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    int n, m;
    cin >> n >> m;
    using arr2 = array <int, 2>;
    map <arr2, string> mp;
    arr2 st, en;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'A') st[0] = i, st[1] = j;
            if (v[i][j] == 'B') en[0] = i, en[1] = j;
        }
    }

    vector <vector <int> > a(n + 1, vector <int> (m + 1));

    vector <vector <int> > vis(n + 1, vector <int> (m + 1));
    queue <arr2> q;
    q.push({st[0], st[1]});
    vis[st[0]][st[1]] = true;
    bool ok = false;
    while (!q.empty()) {
        auto [x, y] = q.front();
        if (x == en[0] && y == en[1]) {
            ok = true;
            break;
        }
        q.pop();
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if (vis[xx][yy] || v[xx][yy] == '#') continue;
            vis[xx][yy] = true;
            a[xx][yy] = k;
            q.push({xx, yy});
        }
    }
    
    if (!ok) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    arr2 cur = {en[0], en[1]};
    string ans;
    while (cur != st) {
        if (a[cur[0]][cur[1]] == 0) {
            ans += 'D';
            cur[0]--;
        }else if (a[cur[0]][cur[1]] == 1) {
            ans += 'L';
            cur[1]++;
        }else if (a[cur[0]][cur[1]] == 2) {
            ans += 'U';
            cur[0]++;
        }else if (a[cur[0]][cur[1]] == 3) {
            ans += 'R';
            cur[1]--; 
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
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