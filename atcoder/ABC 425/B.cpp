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
    vector <bool> vis(n + 1, false);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] == -1) {
            continue;
        }
        if (!vis[v[i]]) {
            vis[v[i]] = true;
        }else {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';

    for (int i = 1; i <= n; i++) {
        if (v[i] == -1) {
            for (int j = 1; j <= n; j++) {
                if (!vis[j]) {
                    v[i] = j;
                    vis[j] = true;
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
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