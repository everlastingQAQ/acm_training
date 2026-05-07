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

ll n, m, k;

void solve ()
{
    cin >> n >> m >> k;
    vector <ll> v(n + 1, m);
    vector <ll> ans;

    while (k--) {
        ll a, b;
        cin >> a >> b;
        v[a]--;
        if (v[a] == 0) {
            ans.emplace_back(a);
        }
    }

    for (auto x : ans) {
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