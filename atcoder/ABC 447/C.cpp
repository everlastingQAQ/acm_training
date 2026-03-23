#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s, t = ' ' + t;

    string temp1, temp2;
    for (char c : s) {
        if (c != 'A') temp1.push_back(c);
    }
    for (char c : t) {
        if (c != 'A') temp2.push_back(c);
    }
    if (temp1 != temp2) {
        cout << -1 << '\n';
        return;
    }

    int ls = 1, rs = 1;
    int lt = 1, rt = 1;
    int ans = 0;
    while (rs <= n || rt <= m) {
        while (rs <= n && s[rs] == 'A') {
            rs++;
        }
        while (rt <= m && t[rt] == 'A') {
            rt++;
        }
        int ct = rt - lt + 1;
        int cs = rs - ls + 1;
        ans += abs(ct - cs);
        rt++;
        lt = rt;
        rs++;
        ls = rs;
    }

    cout << ans << '\n';
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