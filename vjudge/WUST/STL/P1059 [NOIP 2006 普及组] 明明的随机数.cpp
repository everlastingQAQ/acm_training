#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;

    set <ll> s;

    ll t;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (s.find(t) != s.end()) {
            cnt++;
        }
        s.insert(t);
    }

    cout << n - cnt << endl;

    for (ll x : s) {
        cout << x << ' ';
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