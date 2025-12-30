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
    ll n, x, y; cin >> n >> x >> y;
    string s; cin >> s;
    vector <ll> v(n);
    for (ll &a : v) cin >> a;
    
    if (accumulate(v.begin(), v.end(), 0LL) > x + y) {
        cout << "No" << '\n';
        return;
    }

    ll mna = 0, mnb = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            mna += v[i] / 2 + 1;
        }else {
            mnb += v[i] / 2 + 1;
        }
    }

    if (mna > x || mnb > y) {
        cout << "No" << '\n';
        return;
    }

    ll t = s[0];
    bool found = false;
    for (int i = 1; i < n; i++) {
        if (s[i] != t) {
            found = true;
            break;
        }
    }

    if (!found) {
        if (s[0] == '0' && x - y < n) {
            cout << "No" << '\n';
            return;
        }else if (s[1] == '1' && y - x < n) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
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