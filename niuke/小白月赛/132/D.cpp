#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    if (n != m || n == 1 || m == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << 2 << '\n';
    vector <vector <int> > v(n + 1, vector <int> (n + 1));
    vector <int> pos(n + 1, 1);
    iota(pos.begin() + 1, pos.end(), 1);
    int x = 1;
    for (int k = 1; k <= n; k++) {
        // int x = pos[1];
        for (int i = 1; i <= n; i++) {
            v[i][pos[i]] = k;
            pos[i] = (pos[i]) % n + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << v[i][j] << " \n"[j == n];
        }
    }
}

int32_t main ()
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