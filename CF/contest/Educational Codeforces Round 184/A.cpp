#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, a;

void solve ()
{
    cin >> n >> a;
    vector <ll> v(n + 1);
    bool found = true;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] != a) {
            found = false;
        }
    }

    if (found) {
        cout << 1 << '\n';
        return;
    }

    sort(v.begin() + 1, v.end());
    ll pos = 1;
    for (int i = 1; i <= n; i++) {
        if (a > v[i]) {
            pos = i;
        }
    }

    //cout << pos << ' ' << n - pos << '\n';

    if (pos >= n - pos) {
        cout << a - 1 << '\n';
    }else {
        cout << a + 1 << '\n';
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