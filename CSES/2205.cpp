#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        i64 t = i ^ (i >> 1);
        for (int j = n - 1; j >= 0; j--) {
            cout << (t >> j & 1);
        }
        cout << '\n';
    }
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