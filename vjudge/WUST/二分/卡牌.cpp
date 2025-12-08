#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, m;

bool check (ll x, const vector <ll> &a, const vector <ll> &b)
{
    ll nd = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] + b[i] < x) {
            return false;
        }
        nd += max(1LL * 0, x - a[i]);
    }
    
    return nd <= m;
}

void solve ()
{
    cin >> n >> m;
    vector <ll> a(n);
    vector <ll> b(n);

    ll l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        r = max(r, a[i] + b[i]);
    }

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid, a, b)) {
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }

    cout << r << '\n';
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