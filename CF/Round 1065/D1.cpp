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
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <ll> mx(n + 1);
    ll mnn = inf;
    vector <ll> mn(n + 1);
    ll mxx = 0;

    for (int i = 1; i <= n; i++) {
        mnn = min(mnn, v[i]);
        mn[i] = mnn;
    }

    for (int i = n; i >= 1; i--) {
        mxx = max(mxx, v[i]);
        mx[i] = mxx;
    }

    for (int i = 1; i <= n; i++) {
        if (mn[i - 1] > mx[i]) {
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