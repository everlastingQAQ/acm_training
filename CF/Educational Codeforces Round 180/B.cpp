#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (i >= 2) {
            if (abs(v[i] - v[i - 1]) <= 1) {
                ok = true;
            }
        }
    }
    if (ok) {
        cout << "0\n";
        return;
    }

    if (is_sorted(v.begin() + 1, v.end()) || is_sorted(v.begin() + 1, v.end(), greater<>())) {
        cout << "-1\n";
        return;
    }else {
        cout << "1\n";
        return;
    }
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