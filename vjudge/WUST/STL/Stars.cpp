    #include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    while (cin >> n) {
        vector <vector<ll> > v(MAXN + 1, vector<ll> (MAXN + 1, 0));
        vector <pair<ll, ll> > p;
        ll a, b;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            p.push_back({a, b});
            v[a][b] = 1;
        }

        for (int i = n - 1; i > 0; i--) {
            for (int j = 1; j <= n; j++) {
                if (i == n - 1 && j == 1) {
                    continue;
                }

                if (i == n - 1 && j != 1) {
                    v[i][j] += v[i][j - 1];
                    continue;
                }else if (j == 1 && i != n - 1) {
                    v[i][j] += v[i - 1][j];
                    continue;
                }

                v[i][j] += v[i - 1][j];
                
            }
        }
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