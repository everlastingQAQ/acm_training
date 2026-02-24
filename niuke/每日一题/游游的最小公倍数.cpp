#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n;
    cin >> n;
    if (n & 1) {
        cout << n / 2 << ' ' << n - n / 2 << '\n';
    }else {
        i64 a = n / 2, b = n / 2;
        while (lcm(a, b) != a * b) a--, b++;
        cout << a << ' ' << b << '\n';
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