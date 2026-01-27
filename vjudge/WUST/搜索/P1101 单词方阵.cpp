#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;
char c[101][101];
char ans[101][101];
string s = "yizhong";
ll dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
ll dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void dfs (ll x, ll y)
{
    for (int i = 0; i < 8; i++) {
        bool found = true;
        for (int j = 0; j <= 6; j++) {
            ll xx = x + dx[i] * j;
            ll yy = y + dy[i] * j;
            if (xx < 1 || xx > n || yy < 1 || yy > n) {
                found = false;
                break;
            }
            if (c[xx][yy] != s[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            for (int k = 0; k <= 6; k++) {
                ll xx = x + dx[i] * k;
                ll yy = y + dy[i] * k;
                ans[xx][yy] = s[k];
            }
        }
    }
}

void solve ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans[i][j] = '*';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i][j] != 'y') continue;
            dfs(i, j);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}   

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _; 
    while (_--) {
        solve();
    }
    return 0;
}