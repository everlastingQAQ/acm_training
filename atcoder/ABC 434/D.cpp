#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 1e9 + 7;

ll n;

void solve ()
{
    cin >> n;
    vector <pi> a(n);
    vector <pi> b(n);
    vector <vector <ll> > d(2005, vector <ll> (2005, 0));
    vector <vector <ll> > dd(2005, vector <ll> (2005, 0));

    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> b[i].fi >> a[i].se >> b[i].se;
        d[a[i].fi][a[i].se]++;
        d[a[i].fi][b[i].se + 1]--;
        d[b[i].fi + 1][a[i].se]--;
        d[b[i].fi + 1][b[i].se + 1]++;
    }

    ll sum = 0;
    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            d[i][j] = d[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            if (d[i][j] == 1) {
                dd[i][j]++;
            }else if (d[i][j] == 0) {
                sum++;
            }
        }
    }

    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            dd[i][j] = dd[i][j] + dd[i - 1][j] + dd[i][j - 1] - dd[i - 1][j - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        ll t = dd[b[i].fi][b[i].se] - dd[b[i].fi][a[i].se - 1] - dd[a[i].fi - 1][b[i].se] + dd[a[i].fi - 1][a[i].se - 1];
        cout << sum + t << '\n';
    }
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