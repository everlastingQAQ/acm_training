#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    string s; cin >> s;
    vector <int> pos;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') pos.push_back(i + 1);
    }

    for (int i = 0; i < pos.size(); i += 2) {
        cout << pos[i] << ',' << pos[i + 1] << '\n';
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