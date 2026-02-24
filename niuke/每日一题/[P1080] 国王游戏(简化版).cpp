#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    i64 a, b;
    cin >> a >> b;
    vector <array <i64, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    sort(v.begin() + 1, v.end(), [] (auto p, auto q) {
        return p[0] * p[1] < q[0] * q[1];
    });

    i64 ans = 0;
    i64 cur = a;

    for (int i = 1; i <= n; i++) {
        i64 t = cur / v[i][1];
        ans = max(ans, t);
        cur *= v[i][0];
    }

    cout << ans << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/