#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

int vis[20000005];

void solve ()
{
    ll n; cin >> n;
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 1) cnt++;
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 1) cout << i << ' ';
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _ = 1;
    // cin >> _;

    for (int i = 1; i < 4473; i++) {
        if (i * i > 2e7 + 2) break;
        for (int j = i + 1; j < 4473; j++) {
            if (i * i + j * j > 2e7 + 2) break;
            vis[i * i + j * j]++;
        }
    }

    while (_--) {
        solve();
    }
    return 0;
}