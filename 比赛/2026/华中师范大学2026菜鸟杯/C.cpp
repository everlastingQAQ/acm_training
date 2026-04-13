#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
    
void solve ()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (n > m) {
        for (int i = 0; i < k; i++) {
            cout << '0';
        }
        int t0 = n - k;
        for (int i = 0; i < t0; i++) {
            cout << "10";
        }
        int l = m - t0;
        for (int i = 0; i < l; i++) {
            cout << '1';
        }
    }else {
        for (int i = 0; i < k; i++) {
            cout << '1';
        }
        int t0 = m - k;
        for (int i = 0; i < t0; i++) {
            cout << "01";
        }
        int l = n - t0;
        for (int i = 0; i < l; i++) {
            cout << '0';
        }
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