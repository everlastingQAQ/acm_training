#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <array <int, 4> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
    }
    int a, b;
    cin >> a >> b;
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        int x0 = v[i][0];
        int y0 = v[i][1];
        int x1 = v[i][0] + v[i][2];
        int y1 = v[i][1] + v[i][3];
        if (a >= x0 && a <= x1 && b >= y0 && b <= y1) ans = i;
    }
    cout << ans << '\n';
} 
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 