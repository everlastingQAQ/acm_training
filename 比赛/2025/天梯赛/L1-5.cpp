#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    vector <int> cnt(26, 0);
    vector <int> v(26);
    for (int i = 0; i < 26; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for (char c : s) {
        cnt[c - 'a']++;
        ans += v[c - 'a'];
    }
    for (int i = 0; i < 26; i++) {
        if (i < 25) cout << cnt[i] << ' ';
        else cout << cnt[i] << '\n';
    }
    cout << ans;
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