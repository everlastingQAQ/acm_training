#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, char>;

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
    vector <ll> v(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> v[i];
    }
    vector <ll> ans(n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        if (i & 1) ans[1] -= v[i];
        else ans[1] += v[i];
    }

    ans[2] += v[2 * n] - v[1];
    for (int i = 2; i <= 2 * n - 1; i++) {
        if (i & 1) ans[2] += v[i];
        else ans[2] -= v[i];
    }   

    for (int i = 3; i <= n; i++) {
        ans[i] = ans[i - 2] + 2 * (v[2 * n - i + 2] - v[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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