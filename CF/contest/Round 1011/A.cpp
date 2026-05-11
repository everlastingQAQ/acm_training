#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 0) {
        string t = s;
        ranges::reverse(t);
        if (t <= s) {
            cout << "NO\n";
        }else {
            cout << "YES\n";
        }
    }else {
        char c = s[0];
        bool ok = false;
        for (char x : s) {
            if (x != c) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}   
    
int32_t main ()
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