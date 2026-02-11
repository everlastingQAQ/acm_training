#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    vector <string> v;
    string s;
    while (cin >> s) {
        v.push_back(s);
    }
    ranges::reverse(v);
    for (string t : v) {
        for (char x : t) {
            if (x >= '0' && x <= '9') {
                ranges::reverse(t);
                cout << t;
                break;
            }
            if (islower(x)) {
                cout << (char)toupper(x);
            }else {
                cout << (char)tolower(x);
            }
        }
        cout << " ";
    }
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