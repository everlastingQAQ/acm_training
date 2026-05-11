#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int l = 1, r = 1;
    while (r <= n) {
        while (r <= n && v[r] == v[l]) {
            r++;
        }
        int cnt = r - l;
        if (cnt >= m) {
            cout << "NO\n";
            return;
        }
        l = r;
    }
    cout << "YES\n";
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