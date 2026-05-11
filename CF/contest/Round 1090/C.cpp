#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    int r = 3 * n, l = 1;
    while (r >= l) {
        cout << r << ' ';
        r--;
        if (r < l) break;
        cout << r << ' ';
        r--;
        if (r < l) break;
        cout << l << ' ';
        l++;
    }
    cout << '\n';
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