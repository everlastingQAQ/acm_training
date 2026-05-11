#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        sum += t;
    }
    cout << (((sum & 1) || !((k * n) & 1)) ? "YES\n" : "NO\n");
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