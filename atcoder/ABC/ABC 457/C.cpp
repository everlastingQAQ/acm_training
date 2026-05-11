#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <vector <int> > v(n + 1);
    vector <int> len(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> len[i];
        v[i].push_back(0);
        for (int j = 1; j <= len[i]; j++) {
            int t;
            cin >> t;
            v[i].push_back(t);
        }
    }

    vector <int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    int idx = 1;
    int pos = 0;
    while (idx <= n) {
        if (pos + len[idx] * c[idx] >= k) {
            int t = k - pos;
            int tt = (t - 1) % len[idx] + 1;
            cout << v[idx][tt] << '\n';
            return;
        }
        pos += len[idx] * c[idx];
        idx++;
    }
}   

int32_t main ()
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