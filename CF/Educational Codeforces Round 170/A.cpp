#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	string s, t;
    cin >> s >> t;
    int l = 0, r = 0;
    while (l < s.size() && r < t.size() && s[l] == t[r]) {
        l++;
        r++;
    }
    int ans = s.size() + t.size() - l + (l > 0 ? 1 : 0);
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