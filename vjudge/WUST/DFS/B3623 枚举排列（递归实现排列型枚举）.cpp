#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, k;
vector<ll> ans;
vector<bool> vis(11);

void dfs (ll pos, ll cnt)
{
    if (cnt == k) {
        for (auto x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (i == pos || vis[i]) continue;
        ans.push_back(i);
        vis[i] = true;
        dfs(i, cnt + 1);
        ans.pop_back();
        vis[i] = false;
    }
}

void solve ()
{
    cin >> n >> k;
    dfs(0, 0);
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
