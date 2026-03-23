#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int v, n;
    cin >> v >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector <int> dp(v + 1, -1e9);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= a[i]; j--) {
            if (dp[j - a[i]] != -1e9) {
                dp[j] = 1;
            }
        }
    }

    for (int i = v; i >= 0; i--) {
        if (dp[i] != -1e9) {
            cout << v - i << '\n';
            return;
        }
    }
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