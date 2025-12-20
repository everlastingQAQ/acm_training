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

ll qpow (ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    ll n, k; cin >> n >> k;
    vector <ll> a;
    map <ll, ll> mp;
    for (int i = 0; i <= 33; i++) {
        if ((n >> i) & 1) a.push_back(i), mp[i] = 1;
    }
    ll mxpos = a[a.size() - 1];

    ll t;
    if (k & 1) t = k;
    else t = k - 1;

    ll temp = 0;
    ll tt = 1;
    for (int i = 0; i <= mxpos; i++) {
        if (mp[i]) {
            temp += tt;
        }
        tt *= 2;
    }   

    vector <ll> ans(k);
    for (int i = 0; i < t; i++) {
        ans[i] += temp;
    }

    for (auto x : ans) {
        cout << x << ' ';
    }
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