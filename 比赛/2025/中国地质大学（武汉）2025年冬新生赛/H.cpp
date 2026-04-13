#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, p, q;

void solve ()
{
    cin >> n >> p >> q;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    ll sum = 0;
    for (int i = 1; i <= p; i++) {
        sum += v[i];
    }

    ll l = 1, r = p + 1;    
    ll ans = sum;

    while (r <= n) {
        sum += v[r] - v[l];
        l++;
        r++;
        ans = max(ans, sum);
    }

    ans /= p;

    cout << ans << '\n';
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