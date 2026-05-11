#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, m; cin >> n >> m;
    vector <int> v(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
    }
    vector <array <int, 2> > a(m + 1);
    for (int i = 1; i <= m; i++) {
        a[i][0] = v[i] / 100, a[i][1] = i;
    }
    ranges::sort(a | views::drop(1), [] (const auto p, const auto q) {
        return p[0] < q[0];
    });

    int l = 1, r = m;
    int cnt = 0;
    while (l <= r && cnt < n) {
        int x = a[l][1];
        int y = a[r][1];
        for (int i = 0; i < 3; i++) {
            cout << v[x] << ' ' << v[y] << " \n"[i == 2];
        }
        cnt++;
        if (cnt >= n) break;
        for (int i = 0; i < 3; i++) {
            cout << v[y] << ' ' << v[x] << " \n"[i == 2];
        }
        cnt++;
        l++;
        r--;
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