#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    if (s == "0") {
        cout << "NO\n";
        return;
    }
    for (auto c : s) {
        if (c == '5' || c == '0') {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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