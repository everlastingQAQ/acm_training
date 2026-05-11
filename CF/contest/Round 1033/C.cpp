#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    if (m < n || m > n * (n + 1) / 2) {
        cout << -1 << '\n';
        return;
    }
    int cnt = 0;
    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        if (m > n - i + 1) {
            m -= n - i + 1;
            ans.push_back(i);
        }else {
            for (int j = i; j <= n - m; j++) {
                ans.push_back(i - 1);
            }
            for (int j = n - m + 1; j <= n; j++) {
                ans.push_back(i);
            }
            break;
        }
    }

    int rub = ans.back() + 1;
    int pre = ans.back();
    cout << pre << '\n';
    for (int i = n - 2; i >= 0; i--) {
        if (ans[i] == ans[i + 1]) {
            cout << pre << ' ' << rub++ << '\n';
            pre = rub - 1;
        }else {
            cout << pre << ' ' << ans[i] << '\n';
            pre = ans[i];
        }
    }

} 
    
int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 