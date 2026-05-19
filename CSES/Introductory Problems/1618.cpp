#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n;
    cin >> n;
    i64 ans = 0;
    while (n > 0) {
        n /= 5;
        ans += n;
    }
    cout << ans << '\n';
}

int main() {
    solve();
    return 0;
}