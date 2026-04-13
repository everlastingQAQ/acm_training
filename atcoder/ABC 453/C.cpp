#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for (i64 mask = 0; mask < (1 << n); mask++) {
        int cnt = 0;
        double cur = 0.5;
        for (int i = 1; i <= n; i++) {
            if (mask >> (i - 1) & 1) {
                if (cur < 0 && cur + v[i] >= 0) cnt++;
                else if (cur > 0 && cur + v[i] <= 0) cnt++;
                cur += v[i];
            }else {
                if (cur < 0 && cur - v[i] >= 0) cnt++;
                else if (cur > 0 && cur - v[i] <= 0) cnt++;
                cur -= v[i];
            }
        }
        ans = max(ans, cnt);
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
