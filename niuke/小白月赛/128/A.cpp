#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    string s, t; cin >> s >> t;
    for (char &c : s) {
        if (c == 'O') c = '0';
        if (c == 'l' || c == 'I') c = '1';
    }
    for (char &c : t) {
        if (c == 'O') c = '0';
        if (c == 'l' || c == 'I') c = '1';
    }

    cout << (s == t ? "YES" : "NO") << '\n';
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