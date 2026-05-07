#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <string> v(n);
    i64 mx = -1;
    for (string &s : v) {
        cin >> s;
        mx = max(mx, (i64)s.size());
    }

    for (string s : v) {
        if (s.size() == mx) {
            cout << s << '\n';
            continue;
        }
        i64 t = mx - s.size();
        cout << string(t / 2, '.');
        cout << s;
        cout << string(t / 2, '.');
        cout << '\n';
    }
}   
    
int main ()
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/