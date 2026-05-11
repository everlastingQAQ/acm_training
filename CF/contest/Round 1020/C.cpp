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
    ll n, k; cin >> n >> k;
    vector <ll> a(n), b(n);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    bool found = false;
    for (ll x : b) {
        if (x != -1) found = true;
    }

    if (!found) {
        ll mn = *max_element(a.begin(), a.end());
        ll mx = *min_element(a.begin(), a.end()) + k;
        if (mx >= mn) {
            cout << mx - mn + 1 << '\n';
        }else {
            cout << 0 << '\n';
        }
        return;
    }

    vector <ll> v;  
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            v.push_back(b[i] + a[i]);
        }
    }

    for (int i = 1; i < v.size(); i++) {
        if (v[i] != v[0]) {
            cout << 0 << '\n';
            return;
        }
    }

    ll t = v[0];

    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            ll d = t - a[i];
            if (d < 0 || d > k) {
                cout << 0 << '\n';
                return;
            }
        } 
    }

    cout << 1 << '\n';
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