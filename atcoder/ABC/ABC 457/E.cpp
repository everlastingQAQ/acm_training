#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <array <int, 2> > v(m + 1);
    vector <set <int> > st1(n + 1), st2(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> v[i][0] >> v[i][1];
        st1[v[i][0]].insert(v[i][1]);
        st2[v[i][1]].insert(v[i][0]);
    }

    sort(v.begin() + 1, v.end());

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
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