#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
ll n, m, c;

bool cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> n >> m >> c;

    vector<vector<ll>> a(m + 1, vector<ll> (n + 1));
    vector<vector<ll>> s(m + 1, vector<ll> (n + 1));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]; 
        }
    }

    ll mx = 0;
    ll x = 0;
    ll y = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - c >= 0 && j - c >= 0) {
                ll t = s[i][j] - s[i - c][j] - s[i][j - c] + s[i - c][j - c];
                if (t > mx) {
                    mx = t;
                    x = i - c + 1;
                    y = j - c + 1;
                }
            } 
        }
    }

    cout << x << ' ' << y << endl;

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