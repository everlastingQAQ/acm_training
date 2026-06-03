#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s;
    cin >> s;
    int ans = 1e9;
    for (int i = 0; i <= s.size() - 3; i++) {
        string ss = s.substr(i, 3);
        // cout << ss << '\n';
        int x = stoll(ss);
        ans = min(ans, abs(753 - x));
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