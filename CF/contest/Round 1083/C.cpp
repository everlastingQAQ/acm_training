#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        int op;
        cin >> op;
        vector <int> t(op + 1);
        for (int j = 1; j <= op; j++) {
            cin >> t[j];
        }
        map <int, int> mp;
        for (int j = op; j >= 1; j--) {
            if (!mp[t[j]]) {
                v[i].push_back(t[j]);
                mp[t[j]] = 1;
            }
        }
    }

    vector <int> ans;
    map <int, int> mp_num;
    map <int, int> mp_pos;

    for (int i = 1; i <= n; i++) {
        vector <int> tt;
        int pos = 0;    
        for (int j = 1; j <= n; j++) {  
            vector <int> t; 
            if (mp_pos[j]) continue;
            for (int x : v[j]) {
                if (!mp_num[x]) {
                    t.push_back(x);
                }
            }
            if (!pos || t < tt) {
                tt = t;
                pos = j;
            }
        }

        mp_pos[pos] = true;
        for (int x : v[pos]) {
            if (!mp_num[x]) {
                ans.push_back(x);
                mp_num[x] = true;
            }
        }
    }

    for (auto x : ans) {
        cout << x << " \n"[x == ans.back()];
    }
}   
    
int main ()
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