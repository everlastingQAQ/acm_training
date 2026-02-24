#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int idx = 0;
    while (idx < n) {
        int cnt = 0;
        while (idx < n && s[idx] == '1') {
            idx++;
            cnt++;
        }
        if (cnt == 1) {
            cout << "NO\n";
            return;
        }
        idx++;
    }
    cout << "YES\n";
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/