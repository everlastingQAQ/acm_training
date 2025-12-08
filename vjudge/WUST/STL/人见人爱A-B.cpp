#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, m;

void solve ()
{
    set <ll> a;
    set <ll> b;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            return;
        }
        a.clear();
        b.clear();
        ll t;
        for (int i = 0; i < n; i++) {
            cin >> t;
            a.insert(t);
        }
        for (int i = 0; i < m; i++) {
            cin >> t;
            b.insert(t);
        }

        vector <ll> v;
        for (ll i : a) {
            if (!b.count(i)) {
                v.emplace_back(i);
            }
        }
        
        if (!v.empty()) {
            for (ll i : v) {
                cout << i << ' ';
            }
            cout << '\n';
        }else {
            cout << "NULL" << '\n';
        }
        
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