#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	cout << n / 3600 << ' ' << (n - (n / 3600) * 3600) / 60 << ' ' << n - (n / 3600) * 3600 - (n - (n / 3600) * 3600) / 60 * 60 << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 