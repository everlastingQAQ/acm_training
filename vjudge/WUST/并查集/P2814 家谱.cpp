#include <bits/stdc++.h>
using namespace std;
#define int long long

class DSU {
    public:
        map <string, string> mp;
        DSU (int n = 0) {}

        string find (string s) {
            if (!mp.count(s)) mp[s] = s;
            return s == mp[s] ? s : (mp[s] = find(mp[s]));
        }

        void merge (string fa, string s) {
            fa = find(fa), s = find(s);
            mp[s] = fa;
        }
};

void solve ()
{   
    char c;
    string fa;
    DSU dsu;
    while (cin >> c) {
        if (c == '#') {
            cin >> fa;
            continue;
        }
        if (c == '$') return;
        if (c == '+') {
            string s; cin >> s;
            dsu.merge(fa, s);
        }
        if (c == '?') {
            string s; cin >> s;
            cout << s << ' ' << dsu.find(s) << '\n';
        }
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