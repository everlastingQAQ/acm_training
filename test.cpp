#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int cnt = 0;    
    int t = 777777488888889992;
    while (t >= 10) {
        string s = to_string(t);
        int cur = 1;
        for (char c : s) {
            cur *= (c - '0');
        }
        t = cur;
        cnt++;
        cout << cur << ' ';
    }
    cout << cnt << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/