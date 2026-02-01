#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') a.push_back(i + 1); // 1-based
    }

    if (a.empty()) {
        // 全 0 时，最少需要 (n+2)/3 人
        cout << (n + 2) / 3 << '\n';
        return;
    }

    int ans = a.size();
    int m = a.size();

    // 1. 左边：a[0]-1 个空位，最少需要 (a[0]-1)/3 人
    // 例如 0001 (t=3) -> 1001, 增加 3/3=1 人
    ans += (a[0] - 1) / 3;

    // 2. 右边：n-a[m-1] 个空位，最少需要 (n-a[m-1])/3 人
    // 例如 1000 (t=3) -> 1001, 增加 3/3=1 人
    ans += (n - a[m - 1]) / 3;

    // 3. 中间：a[i]-a[i-1]-1 个空位
    for (int i = 1; i < m; i++) {
        int t = a[i] - a[i - 1] - 1;
        if (t >= 3) {
            // 在中间 t 个 0 中，为了让它“饱和”，最少需要 (t-1)/3 个人？
            // 让我们代入测试：t=5 (1000001) -> (5-1)/3 = 1。
            // 变成 1001001，确实只需要加 1 个人！
            // 之前的公式 (t-1)/3 其实逻辑是对的。
            ans += (t - 1) / 3;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}