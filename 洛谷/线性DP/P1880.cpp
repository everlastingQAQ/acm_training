#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    cin >> n;
    vector <i64> v(2 * n + 1), pre(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i + n] = v[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }

    vector <vector <i64> > dp1(2 * n + 1, vector <i64> (2 * n + 1, 1e17));
    vector <vector <i64> > dp2(2 * n + 1, vector <i64> (2 * n + 1, -1e17));
    for (int i = 1; i <= 2 * n; i++) {
        dp1[i][i] = 0;
        dp2[i][i] = 0;
    }

    for (int i = 2; i <= 2 * n; i++) {
        for (int j = 1; j + i - 1 <= 2 * n; j++) {
            int l = j, r = j + i - 1;
            i64 val = pre[r] - pre[l - 1];
            for (int k = l; k < r; k++) {
                dp1[l][r] = min(dp1[l][r], dp1[l][k] + dp1[k + 1][r] + val);
                dp2[l][r] = max(dp2[l][r], dp2[l][k] + dp2[k + 1][r] + val);
            }
        }
    }

    i64 a1 = 1e18, a2 = -1e18;
    for (int i = 1; i <= n; i++) {
        a1 = min(a1, dp1[i][i + n - 1]);
        a2 = max(a2, dp2[i][i + n - 1]);
    }
    cout << a1 << '\n';
    cout << a2 << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 
