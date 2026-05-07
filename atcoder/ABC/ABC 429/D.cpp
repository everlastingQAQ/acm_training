#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m, c;

void solve ()
{
    cin >> n >> m >> c;
    vector <ll> a(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);

    for (int i = 1; i <= n; i++) {
        a[i + n] = a[i];
    }

    ll l = 1, r = 1;
    ll ans = 0;

    while (l <= n) {
        if (r - l < c) { 
            r++;
        }else {
            while (r - l < n && a[r] == a[r + 1]) {
                r++;
            }
            if (l == n) {
                ans += (a[1] + (m - a[n])) * (r - l);
            }else {
                ans += (a[l + 1] - a[l]) * (r - l);
            }
            l++;
        }
    }

    cout << ans << '\n';
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