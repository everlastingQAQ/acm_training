#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e7;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    cout << v[n] * n << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}