#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    map <ll, ll> mp;
    ll mx = 0;
    ll p = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
        if (mp[v[i]] >= mx) {
            if (v[i] > p) {
                mx = v[i];
            }
        }
    }

    sort(v.begin() + 1, v.end(), greater<ll> ());

    
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