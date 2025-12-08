#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;
    ll t;
    ll mn = 1e9 + 1;
    ll mx = -1e9 - 1;
    for (int i = 0; i < n; i++) {
        cin >> t;
        mn = min(mn, t);
        mx = max(mx, t);
    }

    ll x;
    cin >> x;
    if (x > mx || x < mn) {
        cout << "NO" << '\n';
    }else {
        cout << "YES" << '\n';
    }
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