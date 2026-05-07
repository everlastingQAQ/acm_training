#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

void solve ()
{
    string s;
    cin >> s;
    map <char, int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]] = (mp[s[i]] + 1) % mod;
        if (s[i] == 'a') {
            mp[s[i]] = ((mp[s[i]] + mp['b']) % mod + mp['c']) % mod;
        }else if (s[i] == 'b') {
            mp[s[i]] = ((mp[s[i]] + mp['a']) % mod + mp['c']) % mod;
        }else if (s[i] == 'c') {
            mp[s[i]] = ((mp[s[i]] + mp['b']) % mod + mp['a']) % mod;
        }
    }
    int ans = ((mp['a'] + mp['b']) % mod + mp['c']) % mod;
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