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
const ll inf = LLONG_MAX;

ll h, w;

void solve ()
{
    cin >> h >> w;
    vector <vector<ll> > v(h + 2, vector<ll> (w + 2, 0));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                v[i][j] = 1;
            }else {
                v[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (v[i][j] == 1) {
                ll t = v[i - 1][j] + v[i + 1][j] + v[i][j - 1] + v[i][j + 1];
                if (t != 2 && t != 4) {
                    cout << "No" << '\n';
                    return;
                }
            }
        }
    }
    cout << "Yes" << '\n';
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