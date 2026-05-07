#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

void solve ()
{
    string s;
    cin >> s;
    int ans = 0;
    int pre = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == s[i - 1]) pre = i;
        ans = (ans + i - pre + 1) % mod;
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