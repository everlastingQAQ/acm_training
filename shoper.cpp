#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            cout << rand() % 100000 << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}