#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    string ans;
    int idx = 0;
    bool ok = false;
    while (idx < n) {
        if (s[idx] == t[idx]) {
            ans.push_back(s[idx]);
        }else {
            if (s[idx] == '?' || t[idx] == '?') {
                if (s[idx] == '?') {
                    ans.push_back(t[idx]);
                }else {
                    ans.push_back(s[idx]);
                }
            }else {
                ans.push_back('!');
                ok = true;
            }
        }
        idx++;
    }   
    cout << ans << '\n';
    cout << (ok ? "Yes\n" : "No\n");
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