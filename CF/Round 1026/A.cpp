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

    sort(v.begin() + 1, v.end());

    ll posb1 = 1;
    ll posb2 = 1;
    ll pose1 = n;
    ll pose2 = n;

    for (int i = 1; i <= n; i++) {
        if (v[i] % 2 == 0) {
            posb1 = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] % 2 == 1) {
            posb2 = i;
            break;
        }
    }
    for (int i = n; i > 0; i--) {
        if (v[i] % 2 == 0) {
            pose1 = i;
            break;
        }
    }
    for (int i = n; i > 0; i--) {
        if (v[i] % 2 == 1) {
            pose2 = i;
            break;
        }
    }
    ll ans = min({posb1 - 1 + n - pose1, posb2 - 1 + n - pose2});
    cout << ans << '\n';
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