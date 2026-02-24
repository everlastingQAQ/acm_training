#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, x;
    cin >> n >> x;
    i64 sum = 0;
    for (int i = 1; i <= n; i++) {
        i64 t;
        cin >> t;
        sum += t;
    }
    cout << (x * n == sum ? "YES\n" : "NO\n");
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