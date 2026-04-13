#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    vector <int> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == a[1] || a[0] == a[2]) {
        cout << "-1";
        return;
    }
    cout << a[1] << ' ' << a[0] << ' ' << a[2] << '\n';
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