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

void solve ()
{
    ll a, b; cin >> a >> b;
    ll aa = a, bb = b;
    ll t = 1;
    ll ans1 = 0;
    while (aa >= 0 && bb >= 0) {
        aa -= t; t *= 2;
        if (aa < 0) break;
        ans1++;
        bb -= t; t *= 2;
        if (bb < 0) break;
        ans1++;
    }
    
    t = 1;
    ll ans2 = 0;
    while (a >= 0 && b >= 0) {
        b -= t; t *= 2;
        if (b < 0) break;
        ans2++;
        a -= t; t *= 2;
        if (a < 0) break;
        ans2++;
    }

    cout << max(ans1, ans2) << '\n';
}   
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}