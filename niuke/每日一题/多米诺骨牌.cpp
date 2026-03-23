#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <i64> h(n + 1), x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    vector <array <i64, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i][1] = h[i] + x[i];
        v[i][0] = x[i];
    }   

    sort(v.begin() + 1, v.end());

    vector <i64> ans;
    int l = 1, r = 1;
    while (r <= n) {
        i64 t = v[r][1];
        int cnt = 0;
        while (r <= n && v[r][0] <= t) {
            cnt++;
            t = max(t, v[r][1]);
            r++;
        }
        ans.push_back(cnt);
    }

    sort(ans.begin(), ans.end(), greater<>());

    i64 res = 0;
    for (int i = 0; i < min(m, (int)ans.size()); i++) {
        res += ans[i];
    }

    cout << res << '\n';
}   
    
int main ()
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