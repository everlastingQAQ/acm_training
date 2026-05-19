#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s;
    cin >> s;
    int cn = 0;
    string ss;
    for (auto c : s) {
        if (c != '4') ss.push_back(c);
        else cn++;
    }
    vector <int> dp(2, 0);
    for (auto c : ss) {
        if (c == '1' || c == '3') {
            dp[1] = min(dp[0], dp[1]);
            dp[0]++;
        }
        if (c == '2') {
            dp[1]++;
        } 
    }
    cout << cn + min(dp[0], dp[1]) << '\n';
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