#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    ll n, m; cin >> n >> m;
    vector <vector <ll> > v(n + 1, vector <ll> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    ll l = 0, r = 1000;
    bool flag = false;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        flag = false;
        vector <vector <bool> > vis(n + 1, vector <bool> (m + 1, false));
        auto dfs = [&] (ll x, ll y, ll t, auto self) -> void {
            if (x == n) {
                flag = true;
                return;
            }
            for (int i = 0; i < 4; i++) {
                ll xx = x + dx[i], yy = y + dy[i];
                if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] || v[xx][yy] > t) continue;
                vis[xx][yy] = true;
                self(xx, yy, t, self);
                if (flag) return;
            }
        };
        dfs(1, 1, mid, dfs);
        if (flag) {
            r = mid - 1;
        }else {
            l = mid + 1; 
        }
    }

    cout << l << '\n';
    
}   
 
int main ()
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