#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m;

void solve ()
{
    cin >> n >> m;
    vector <ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }   
    vector <ll> vis(m + 1, false);

    ll l = 0, r = 0;
    ll cnt = 0;
    ll ans = 0;
    while (r < n) {
        if (vis[v[r]] == 0) {
            vis[v[r]]++;
            r++;
            cnt++;
        }
        if (cnt == m) {
            ans = min(ans, r - l + 1);
            vis[v[l]]--;
            if (vis[v[l]] == 0) {
                cnt--;
            }
            l++;
        }
        
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