#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	i64 x;
    cin >> x;
    if (x <= 2) {
        cout << "No\n";
        return;
    }

    i64 n, m;
    if (x & 1) {
        n = (x + 1) / 2;
        m = (x - 1) / 2;
    }else {
        n = x / 2;
        m = 1;
    }
    cout << "Yes\n";
    cout << n * n - m * m << ' ' << 2 * n * m << ' ' << n * n + m * m << '\n';
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