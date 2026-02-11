#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, q; cin >> n >> q;
    string s; cin >> s;
    s = ' ' + s;
    vector <vector < set <int> > > st(3, vector <set <int> > (3));
    for (int i = 1; i <= q; i++) {
        char x, y; cin >> x >> y;
        st[x - 'a'][y - 'a'].insert(i);
    }
    
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'a') continue;
        if (s[i] == 'b') {
            if (st[1][0].size()) {
                st[1][0].erase(st[1][0].begin());
                s[i] = 'a';
            }else if (st[1][2].size() && st[2][0].size()) {
                auto idx = *st[1][2].begin();
                auto t = st[2][0].lower_bound(idx);
                if (t != st[2][0].end()) {
                    st[1][2].erase(idx);
                    st[2][0].erase(t);
                    s[i] = 'a';
                }
            }
        }else if (s[i] == 'c') {
            if (st[2][0].size()) {
                st[2][0].erase(st[2][0].begin());
                s[i] = 'a';
            }else if (st[2][1].size()) {
                auto idx = *st[2][1].begin();
                st[2][1].erase(idx);
                s[i] = 'b';
                if (st[1][0].size()) {
                    auto t = st[1][0].lower_bound(idx);
                    if (t != st[1][0].end()) {
                        st[1][0].erase(t);
                        s[i] = 'a';
                    }
                }
            }
        }
    }

    cout << s << '\n';
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