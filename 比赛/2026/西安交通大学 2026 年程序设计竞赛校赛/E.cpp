#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, x;
    cin >> n >> x;
    vector <array <int, 2> > dp(n + 1);
    dp[0][0] = dp[0][1] = x;
    for (int i = 1; i <= n; i++) {
        vector <string> v(7);
        for (int j = 1; j <= 6; j++) {
            cin >> v[j];
        }
        int p0, p1;
        auto [p, q] = dp[i - 1];
        if (v[1] == "x") {
            int t = stoll(v[3]);
            if (v[2] == "+") {
                p0 = p + t;
                p1 = q + t;
            }else if (v[2] == "-") {
                p0 = p - t;
                p1 = q - t;
            }else if (v[2] == "*") {
                p0 = p * t;
                p1 = q * t;
            }else if (v[2] == "/") {
                p0 = p / t;
                p1 = q / t;
            }
        }else {
            int t = stoll(v[1]);
            if (v[2] == "+") {
                p0 = p + t;
                p1 = q + t;
            }else if (v[2] == "-") {
                p0 = t - q;
                p1 = t - p;
            }else if (v[2] == "*") {
                p0 = p * t;
                p1 = q * t;
            }else if (v[2] == "/") {
                p0 = t / q;
                p1 = t / p;
            }
        }

        int q0, q1;
        if (v[4] == "x") {
            int t = stoll(v[6]);
            if (v[5] == "+") {
                q0 = p + t;
                q1 = q + t;
            }else if (v[5] == "-") {
                q0 = p - t;
                q1 = q - t;
            }else if (v[5] == "*") {
                q0 = p * t;
                q1 = q * t;
            }else if (v[5] == "/") {
                q0 = p / t;
                q1 = q / t;
            }
        }else {
            int t = stoll(v[4]);
            if (v[5] == "+") {
                q0 = p + t;
                q1 = q + t;
            }else if (v[5] == "-") {
                q0 = t - q;
                q1 = t - p;
            }else if (v[5] == "*") {
                q0 = p * t;
                q1 = q * t;
            }else if (v[5] == "/") {
                q0 = t / q;
                q1 = t / p;
            }
        }
        dp[i][0] = min({p0, q0});
        dp[i][1] = max({p1, q1});
    }
    cout << dp[n][1] << '\n';
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