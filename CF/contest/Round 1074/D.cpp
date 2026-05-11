#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, m, h; cin >> n >> m >> h;
    vector <int> raw(n + 1);
    for (int i = 1; i <= n; i++) cin >> raw[i];
    vector <array<int, 2> > rec(m + 1);
    for (int i = 1; i <= m; i++) cin >> rec[i][0] >> rec[i][1];

    vector <int> v(n + 1); v = raw;
    vector <int> t(n + 1, 0);
    int temp = 0;

    for (int i = 1; i <= m; i++) {
        int a = rec[i][0], b = rec[i][1];
        if (t[a] < temp) {
            v[a] = raw[a];
            t[a] = temp;
        }
        v[a] += b;
        if (v[a] > h) temp = i;
    }

    for (int i = 1; i <= n; i++) {
        if (t[i] < temp) {
            cout << raw[i] << " \n"[i == n];
        }else {
            cout << v[i] << " \n"[i == n];
        }
    }
}   
    
signed main ()
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