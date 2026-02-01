#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s; cin >> s;
    string t;
    bool ok = true;
    for (auto c : s) {
        if (ok && c == '.') {
            t.push_back('o');
            ok = false;
        }else if (!ok && c == '.') {
            t.push_back('.');
        }else if (c == '#') {
            ok = true;
            t.push_back('#');
        }
    }
    cout << t;
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