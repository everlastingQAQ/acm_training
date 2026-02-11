#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, q, s;
    cin >> n >> q >> s;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <array<int, 2> > a(q + 1);
    vector <array<int, 2> > p(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    p = a;

    sort(a.begin() + 1, a.end());

    vector <int> ans(q + 1);
    map <array <int, 2>, int> mp;
    int cur = s - 1;
    int idx = 1;
    for (int i = 1; i <= q; i++) {
        while (idx <= n && idx < a[i][0]) {
            cur += v[idx];
            idx++;
        }
        mp[{a[i][0], a[i][1]}] = cur + a[i][1];
    }

    for (int i = 1; i <= q; i++) {
        cout << mp[{p[i][0], p[i][1]}] << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/