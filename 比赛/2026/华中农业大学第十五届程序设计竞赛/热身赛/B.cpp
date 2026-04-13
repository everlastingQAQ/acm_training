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
    map <ll, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]] = 1;
    }
    bool found = true;
    for (int i = 1; i <= n; i++) {
        if (mp[i] == 0) {
            cout << i << '\n';
            found = false;
            return;
        }
    }
    if (found) {
        cout << n + 1 << '\n';
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