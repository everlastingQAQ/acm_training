#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s;
    cin >> s;
    if (s.size() < 12) {
        cout << "NO\n";
        return;
    }
    string ss = s.substr(0, 9);
    if (ss != "ucup-team") {
        cout << "NO\n";
        return;
    }
    string t;
    for (int i = 9; i < s.size(); i++) {
        if (s[i] > '9' || s[i] < '0') {
            cout << "NO\n";
            return;
        }
        t += s[i];
    }
    if (t[0] == '0') {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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