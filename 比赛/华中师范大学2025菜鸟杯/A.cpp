#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	i64 n, m, k;
  	cin >> n >> m >> k;
  	
    if (n == 1 || m == 1) {n
        cout << -1 << '\n';
        return;
    }

  	i64 sum = 0;
  	i64 l = 1, r = min(n, m);
  	i64 t = n * m * 6 / 10;
  	if ((n * m * 6) % 10 != 0) t++;

    auto check = [&] (i64 x) {
        return x * (n + m) - x * x >= t;
    };

  	while (l <= r) {
        i64 mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }

    cout << l * k << '\n';
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