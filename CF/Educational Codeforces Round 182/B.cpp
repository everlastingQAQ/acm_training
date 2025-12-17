#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;
 
ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    ll cnt = 0;
    ll pos = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] == 0) {
            cnt++;
            pos = i;
        }
    }

    ll l = n + 1, r = 1;
    if (cnt == 1) {
        bool found = false;
        for (int i = 1; i <= n; i++) {
            if (v[i] == pos) {
                found = true;
                break;
            }
        }
        if (!found) {
            for (ll i = 1; i <= n; i++) {
                if (v[i] != i && v[i] != 0) {
                    l = min(l, i);
                    r = max(r, i);
                }
            }
            if (l == n + 1 && r == 1 || (r == l)) {
                cout << 0 << '\n';
            }else {
                cout << r - l + 1 << '\n';
            }
        }else {
            for (ll i = 1; i <= n; i++) {
                if (v[i] == 0 || v[i] != i) {
                    l = min(l, i);
                    r = max(r, i);
                }
            }
            if (l == n + 1 && r == 1 || (r == l)) {
                cout << 0 << '\n';
            }else {
                cout << r - l + 1 << '\n';
            }
        }
    }else {
        for (ll i = 1; i <= n; i++) {
            if (v[i] == 0 || v[i] != i) {
                l = min(l, i);
                r = max(r, i);
            }
        }
        if (l == n + 1 && r == 1 || (r == l)) {
            cout << 0 << '\n';
        }else {
            cout << r - l + 1 << '\n';
        }
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