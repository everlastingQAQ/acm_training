#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    string s; cin >> s; s = ' ' + s;
    vector <int> v(26);
    for (int i = 1; i <= n; i++) {
        v[s[i] - 'a']++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        v[s[i] - 'a']--;
        for (int j = 0; j < 26; j++) {
            if (j == s[i] - 'a') continue;
            ans += max(0LL, v[j] * (v[j] - 1) / 2);
        }
    }

    cout << ans << '\n';
}   
    
signed main ()
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