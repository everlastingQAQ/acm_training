#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, char>;

#define fi first
#define se second

const int N = 3e5;
const double eps = 1e-5;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <vector <ll> > v(n + 5, vector <ll> (n + 5));
    vector <vector <bool> > vis(n + 5, vector <bool> (n + 5, false));
    ll t = 1;
    ll p = n * n;
    ll i = 1, j = n / 2 + 1;
    
    while (p--) {
        vis[i][j] = true;
        v[i--][j++] = t++;
        i = (i + n - 1) % n + 1;
        j = (j + n - 1) % n + 1;
        if (vis[i][j]) {
            i += 2, j--;
        }
        i = (i + n - 1) % n + 1;
        j = (j + n - 1) % n + 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
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