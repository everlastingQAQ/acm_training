#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    // sort(v.begin() + 1, v.end(), greater<>());
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            bool ok = true;
            for (int k = 1; k <= n; k++) {
                if (k == i || k == j) continue;
                // if ((v[i] + v[j]) + v[k] < ans / 2) {
                //     ok = false;
                //     break;
                // }
                ans = max(ans, ((v[i] + v[j]) ^ v[k]));
            }
            if (!ok) break;
        }
    }
    cout << ans << '\n';
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