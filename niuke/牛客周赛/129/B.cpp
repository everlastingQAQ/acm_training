#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s; cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    if (s > t) {
        cout << "left";
    }else if (s == t) {
        cout << "equal";
    }else {
        cout << "right";
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