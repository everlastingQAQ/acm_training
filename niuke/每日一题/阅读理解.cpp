#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    map <string, set<int> > mp;

    for (int i = 1; i <= n; i++) {
        int l; cin >> l;
        for (int j = 1; j <= l; j++) {
            string s; cin >> s;
            mp[s].insert(i);
        }
    }

    int q; cin >> q;
    for (int i = 1; i <= q; i++) {
        string s; cin >> s;
        for (int x : mp[s]) cout << x << ' ';
        cout << '\n';
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