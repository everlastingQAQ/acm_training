#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;  // 凑出 0 的方案数设为 1，作为转移起点

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] += dp[j - i];
        }
    }

    // 打表输出 1~n 的答案
    for (int i = 1; i <= n; i++) {
        cout << "p(" << i << ") = " << dp[i] << '\n';
    }

    return 0;
}