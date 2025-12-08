#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, a, b;
ll ans = 1e9 + 1;
vector<vector<ll> > e(210);
ll temp[210];

void dfs(ll pos, ll cnt)
{
    temp[pos] = cnt;

    if (pos == b) {
        ans = min(ans, cnt);
        return;
    }
    
    for (auto p : e[pos]) {
        if (pos + p <= 0 || pos + p > n) {
            continue;
        }
        if (temp[pos + p] > cnt + 1) {
            dfs(pos + p, cnt + 1);
        }
        
    }
}

void solve ()
{  
    cin >> n >> a >> b;
    ll t;
    for (int i = 1; i <= n; i++) temp[i] = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        e[i].push_back(t);
        e[i].push_back(-t);
    }
    dfs(a, 0);
    if (ans == 1e9 + 1) {
        cout << -1 << '\n';
    }else {
        cout << ans << '\n';
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