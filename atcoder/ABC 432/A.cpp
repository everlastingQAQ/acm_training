#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll a, b, c;

void solve ()
{
    cin >> a >> b >> c;
    ll mx = max({a, b, c});
    ll mn = min({a, b, c});
    ll md = a + b + c - mx - mn;
    
    cout << mx << md << mn;
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