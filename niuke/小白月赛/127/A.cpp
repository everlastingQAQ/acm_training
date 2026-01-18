#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

string s[7] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};

void solve ()
{
    vector <int> v(7);
    for (int i = 0; i < 7; i++) {
        cin >> v[i];
    }
    int mx = ranges::max(v);
    for (int i = 0; i < 7; i++) {
        if (v[i] == mx) {
            cout << s[i] << '\n';
            return;
        }
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