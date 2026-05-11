#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cur = 1;
    int ans = 1;
    map <int, int> mp;
    mp[1] = 1;
    while (1) {
        if (s[cur - 1] == 'R') cur++;
        else cur--;
        if (!mp[cur]) ans++;
        else break;
        if (ans == n) break;
        mp[cur] = 1;
        // cout << cur << ' ' << ans << '\n';
    }
    cout << ans << '\n';
}  

int main ()
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