#include <bits/stdc++.h>
using namespace std;

void solve ()
{
    int n;
    cin >> n;
    int cnt = 0;
    while (cnt <= 10 && cnt * 111 <= n) {
        int t = n - cnt * 111;
        if (t % 11 == 0) {
            cout << "YES\n";
            return;
        }
        cnt++;
    }
    cout << "NO\n";
}   

int32_t main ()
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