#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    vector <int> cnt(22);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        for (int j = 0; j <= 21; j++) {
            if (v[i] >> j & 1) cnt[j]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = 0; j <= 21; j++) {
            if (cnt[j]) {
                cnt[j]--;
                cur += (1LL << j);
            }
        }
        ans += cur * cur;
    }

    cout << ans << '\n';
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