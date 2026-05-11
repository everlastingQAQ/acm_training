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
    ll a = (1LL << n) - 1;
    vector <ll> ans; 
    ans.push_back(a);
    for (ll i = n - 1; i >= 0; i--) {
        a = a ^ (1LL << i);
        for (ll j = 0; j < (1LL << (n - i - 1)); j++) {
            ans.push_back(a + (j << (i + 1)));
        }
    }
    for (ll x : ans) cout << x << ' ';
    cout << '\n';
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