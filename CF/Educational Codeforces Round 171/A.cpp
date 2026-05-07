#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int x, y, k;
    cin >> x >> y >> k;
    if (x > y) swap(x, y);
    cout << 0 << ' ' << 0 << ' ' << x << ' ' << x << '\n';
    cout << 0 << ' ' << x << ' ' << x << ' ' << 0 << '\n';
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