#include<bits/stdc++.h>
using namespace std;
#define int long long

void ovo() {
    int n; cin >> n;
    vector <int> a (2 * n + 1);
    vector <char> b (2 * n + 1);

    for (int i = 1; i <= n; i ++) {
        char c; int x;
        cin >> c >> x;
        b[i] = c; b[i + n] = c;
        a[i] = x; a[i + n] = x;
    }

    const int INF = 1e9;
    vector <vector <int> > dpx (2 * n + 1, vector <int> (2 * n + 1, -INF));
    vector <vector <int> > dpn (2 * n + 1, vector <int> (2 *n + 1, INF));

    for (int i = 1; i <= 2 * n; i ++) {
        dpx[i][i] = a[i];
        dpn[i][i] = a[i];
    }

    for (int len = 2; len <= n; len ++) {
        for (int l = 1; l <= 2 * n - len + 1; l ++) {
            int r = l + len - 1;

            for (int k = l + 1; k <= r; k ++) {
                if (b[k] == 't') {
                    dpx[l][r] = max (dpx[l][r], dpx[l][k - 1] + dpx[k][r]);
                    dpn[l][r] = min (dpn[l][r], dpn[l][k - 1] + dpn[k][r]);
                } else {
                    dpx[l][r] = max (dpx[l][r], dpx[l][k - 1] * dpx[k][r]);
                    dpx[l][r] = max (dpx[l][r], dpn[l][k - 1] * dpn[k][r]);
                    dpn[l][r] = min (dpn[l][r], dpn[l][k - 1] * dpx[k][r]);
                    dpn[l][r] = min (dpn[l][r], dpx[l][k - 1] * dpn[k][r]);
                }
            }
        }
    }

    vector <int> an;
    int ans = -INF;

    for (int i = 1; i <= n; i ++) {
        ans = max (ans, dpx[i][i + n -1]);
    }

    for (int i = 1; i <= n; i ++) {
        if (ans == dpx[i][i + n - 1]) {
            an.push_back (i);
        }
    }

    cout << ans << '\n';
    for (int i = 0; i < an.size(); i ++) {
        cout << an[i] << " \n"[i == an.size() - 1];
    }
}

signed main () {
    ios::sync_with_stdio(false); cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) ovo();
}