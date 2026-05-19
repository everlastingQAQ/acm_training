#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	i64 n;
    cin >> n;
    cout << (1LL << n) - 1 << '\n';
    
    auto dfs = [&] (auto self, int x, int a, int b, int c) -> void {
        if (x == 1) {
            cout << a << ' ' << c << '\n';
        }else {
            self(self, x - 1, a, c, b);
            self(self, 1, a, b, c);
            self(self, x - 1, b, a, c);
        }
    };
    dfs(dfs, n, 1, 2, 3);
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