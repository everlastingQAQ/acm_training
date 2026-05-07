#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    map <char, int> mp;
    int mx = -1;
    for (char c : s) {
        mp[c]++;
        mx = max(mp[c], mx);
    }
    
    for (char c : s) {
        if (mp[c] != mx) {
            cout << c;
        }
    }
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