#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n + 1);
    ll cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] & 1) cnt1++;
        else cnt2++;
    }
    cout << min(cnt1, cnt2) << '\n';
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