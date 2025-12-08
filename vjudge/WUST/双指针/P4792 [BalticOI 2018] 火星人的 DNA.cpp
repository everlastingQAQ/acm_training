#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, k, r;

void solve ()
{
    cin >> n >> k >> r;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <ll> a(k);
    for (int i = 1; i <= r; i++) {
        ll p, q;
        cin >> p >> q;
        a[p] = q;
    }

    ll l = 1, r = 1;
    while (l <= n) {
        
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