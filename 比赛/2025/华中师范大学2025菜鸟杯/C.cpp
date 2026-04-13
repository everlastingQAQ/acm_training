#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	i64 l , r;
  	cin >> l >> r;
  	cout << r - l + 1 - (__lg(r) - __lg(l - 1)) << '\n';
} 
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 