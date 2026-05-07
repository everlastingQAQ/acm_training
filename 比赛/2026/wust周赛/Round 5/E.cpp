#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    string s;
    map <array <int, 2>, int> mp;
    int c0 = 0, c1 = 0, c2 = 0;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '0') c0++;
        if (c == '1') c1++;
        if (c == '2') c2++;
        if (c0 == c1 && c1 == c2) ans++;
        int t1 = c1 - c0;
        int t2 = c2 - c1;
        if (mp.find({t1, t2}) != mp.end()) {
            ans += mp[{t1, t2}];
        }
        mp[{t1, t2}]++;
    }
    cout << ans << '\n';
}

int main ()
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