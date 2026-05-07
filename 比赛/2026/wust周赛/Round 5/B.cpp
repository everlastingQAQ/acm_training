#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <array <int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int j = 1; j <= 3; j++) {
            int x;
            cin >> x;
            t += x;
        }
        v[i][0] = t;
        v[i][1] = i;
    }

    sort(v.begin() + 1, v.end());
    vector <string> ans(n + 1);
    
    for (int i = 1; i <= n; i++) {
        if (v[n - k + 1][0] <= v[i][0] + 300) {
            ans[v[i][1]] = "Yes";
        }else {
            ans[v[i][1]] = "No";
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
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