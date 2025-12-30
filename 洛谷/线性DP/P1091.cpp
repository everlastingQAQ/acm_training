#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    
    vector <ll> a(n + 1);
    vector <ll> pre(n + 1);
    pre[1] = 1;
    a[1] = v[1];
    ll len = 1;

    for (int i = 2; i <= n; i++) {
        ll pos = lower_bound(a.begin() + 1, a.begin() + len + 1, v[i]) - a.begin();
        pre[i] = pos;
        a[pos] = v[i];
        len = max(len, pos);
    }

    vector <ll> b(n + 1);
    vector <ll> suf(n + 1);
    suf[n] = 1;
    b[1] = v[n];
    len = 1;

    for (int i = n - 1; i >= 1; i--) {
        ll pos = lower_bound(b.begin() + 1, b.begin() + len + 1, v[i]) - b.begin();
        suf[i] = pos;
        b[pos] = v[i];
        len = max(len, pos);
    }

    ll mx = 0;

    for (int i = 1; i <= n; i++) {
        mx = max(pre[i] + suf[i] - 1, mx);
    }

    cout << n - mx << '\n';

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