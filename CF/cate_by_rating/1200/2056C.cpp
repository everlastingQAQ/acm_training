#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    if (n == 6) {
        cout << "1 1 2 3 1 2\n";
        return;
    }
    for (int i = 1; i <= n / 2; i++) {
        cout << i << ' ';
    }
    if (n & 1) cout << n - n / 2 << ' ';
    for (int i = 1; i <= n / 2; i++) {
        cout << i << ' ';
    }
    cout << '\n';
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