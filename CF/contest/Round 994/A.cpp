#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int l = 1, r = n;
    while (l <= n && v[l] == 0) {
        l++;
    }
    while (r >= 1 && v[r] == 0) {
        r--;
    }
    if (l == n + 1) {
        cout << 0 << '\n';
        return;
    }
    for (int i = l; i <= r; i++) {
        if (v[i] == 0) {
            cout << 2 << '\n';
            return;
        }
    }
    cout << 1 << '\n';
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