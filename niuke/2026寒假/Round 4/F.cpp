#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int a, b;
    cin >> a >> b;
    if (a >= b) {
        int cnt = b + 1;
        int p = b;
        int t = a / cnt;
        int tt = a % cnt;
        for (int i = 0; i < cnt; i++) {
            cout << string(t, '0');
            if (tt > 0) {
                cout << '0';
                tt--;
            }
            if (p > 0) {
                cout << '1';
                p--;
            } 
        }
        cout << '\n';
    }else {
        int cnt = a + 1;
        int p = a;
        int t = b / cnt;
        int tt = b % cnt;
        for (int i = 0; i < cnt; i++) {
            cout << string(t, '1');
            if (tt > 0) {
                cout << '1';
                tt--;
            }
            if (p > 0) {
                cout << '0';
                p--;
            } 
        }
        cout << '\n';
    }
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