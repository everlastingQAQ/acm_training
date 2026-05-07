#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = int;

void solve ()
{
    string s;
    cin >> s;
    cout << (s[0] == s[s.size() - 1] ? "Yes\n" : "No\n");
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