#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s; cin >> s;
    if (s[1] == s[2]) {
        cout << "Yes" << '\n';
    }else {
        cout << "No" << '\n';
    }
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