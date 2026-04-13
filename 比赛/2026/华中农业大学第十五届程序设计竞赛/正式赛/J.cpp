#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

ll n, m;

void solve ()
{
	cin >> n >> m;
    vector <vector <ll> > v(n + 3, vector <ll> (m + 3));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector <ll> ss(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ss[i] += v[i][j];
        }
    }

    vector <ll> s(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        s[i] = ss[i - 1] + ss[i] + ss[i + 1];
    }

    vector <vector <ll> > sa(n + 2, vector <ll> (m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sa[i][j] = v[i][j] + v[i - 1][j] + v[i][j - 1] + v[i][j + 1];
        }
    }
    vector <vector <ll> > up(n + 2, vector <ll> (m + 2)); 
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (sa[i][j] != 0) {
                up[i][j] = sa[i][j];
            }else {
                up[i][j] = up[i - 1][j];
            }
        }
    }

    vector <vector <ll> > sb(n + 2, vector <ll> (m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sb[i][j] = v[i][j] + v[i + 1][j] + v[i][j - 1] + v[i][j + 1];
        }
    }
    vector <vector <ll> > dw(n + 2, vector <ll> (m + 2)); 
    for (int j = 1; j <= m; j++) {
        for (int i = n; i >= 1; i--) {
            if (sb[i][j] != 0) {
                dw[i][j] = sb[i][j];
            }else {
                dw[i][j] = dw[i + 1][j];
            }
        }
    }

    vector <ll> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            ans[i] += s[i];
            if (n <= 2) continue;
            for (int j = 2; j <= m; j += 3) {
                ans[i] += dw[i + 2][j];
            }
        }else if (i == n) {
            ans[i] += s[n];
            if (n <= 2) continue;
            for (int j = 2; j <= m; j += 3) {
                ans[i] += up[i - 2][j];
            }
        }else {
            ans[i] += s[i];
            if (n <= 2) continue;
            for (int j = 2; j <= m; j += 3) {
                ans[i] += up[i - 2][j] + dw[i + 2][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
