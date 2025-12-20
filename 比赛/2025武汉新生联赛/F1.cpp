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

vector <bool> vis(2e7 + 5, false);
vector <int> v(4e3 + 510);

void solve ()
{
    ll n; cin >> n;
    if (vis[n]) {
        cout << "Yes" << '\n';
    }else {
        cout << "No" << '\n';
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;

    for (int i = 1; i < 4500; i++) {
        v[i] = i * i;
    }
    for (int i = 1; i < 4500; i++) {
        if (v[i] > 2e7 + 4) break;
        for (int j = 1; j < 4500; j++) {
            if (v[i] + v[j] > 2e7 + 4) continue;
            vis[v[i] + v[j]] = true;
        }
    }

    while (_--) {
        solve();
    }
    return 0;
}   