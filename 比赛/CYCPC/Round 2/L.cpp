#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	i64 n;
  	cin >> n;
  	cout << ((n & 1) ? "Daiyousei\n" : "Cirno\n");  
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