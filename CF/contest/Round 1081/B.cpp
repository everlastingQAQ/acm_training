#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> ans1, ans0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') ans1.push_back(i + 1);
        else ans0.push_back(i + 1);
    }
    
    if (n & 1) {
        if (!(ans1.size() & 1)) {
            cout << ans1.size() << '\n';
            for (auto x : ans1) {
                cout << x << " \n"[x == ans1.back()];
            }
        }else {
            cout << -1 << '\n';
        }
    }else {
        if (!(ans1.size() & 1)) {
            cout << ans1.size() << '\n';
            for (auto x : ans1) {
                cout << x << " \n"[x == ans1.back()];
            }
        }else if (ans0.size() & 1) {
            cout << ans0.size() << '\n';
            for (auto x : ans0) {
                cout << x << " \n"[x == ans0.back()];
            }
        }else {
            cout << -1 << '\n';
        }
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/