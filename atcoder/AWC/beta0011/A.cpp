#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, m;
    cin >> n >> m;
    i64 s, t;
    cin >> s >> t;
    vector <array <int, 2> > v(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin() + 1, v.end());
    if (t < s) {
        swap(s, t);
    }
    i64 ans = 0;
    bool ok = false;
    for (int i = 1; i <= m; i++) {
        if (v[i][0] >= s) {
            ok = true;
        }
        if (v[i][0] > t) {
            break;
        }
        if (ok) {
            ans += v[i][1];
        }
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