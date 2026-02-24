#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, k;
    cin >> n >> k;
    if (k & 1) {
        for (int i = 1; i < n; i++) {
            cout << n << ' ';
        }
        cout << n - 1 << '\n';
    }else {
        for (int i = 1; i < n - 1; i++) {
            cout  << n - 1 << ' ';
        }
        cout << n << ' ' << n - 1 << '\n';
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