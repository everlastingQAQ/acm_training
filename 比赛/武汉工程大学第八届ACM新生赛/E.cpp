#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;

void solve ()
{
    cin >> n;
    ll ans = 0, t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        ans += t;
    }
    cout << ans << '\n';
    if (ans <= 100) {
        cout << "Good job" << '\n';
    }else {
        cout << "Statement made by gzd" << '\n';
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