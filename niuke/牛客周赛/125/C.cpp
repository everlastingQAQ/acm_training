#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<string, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    ll ans = 0;
    ll idx = 1;
    ll temp = 1e11;

    while (idx <= n) {
        while (idx <= n && v[idx] == 0) {
            idx++;
        }
        if (idx > n) break;
        while (idx <= n && v[idx] != 0) {
            temp = min(temp, v[idx]);
            idx++;
        }
        ans += temp;
        temp = 1e11;
    }

    cout << ans << '\n';
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