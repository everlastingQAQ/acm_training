#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1);
    int l, r;
    bool ok = false;
    int ans1 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (!ok && (v[i] == n || v[i] == n - 1)) {
            l = i;
            ok = true;
        }
        if (ok && (v[i] == n || v[i] == n - 1)) {
            r = i;
        }
    }

    bool found = true;
    for (int i = 2; i <= n - 1; i++) {
        if (v[i] == max({v[i - 1], v[i], v[i + 1]})) {
            found = false;
            break;
        }
    }
    if (found) {
        cout << 0 << '\n';
        return;
    }

    int ans = l - 1 + n - r;

    for (int i = l + 1; i < r; i++) {
        if (v[i] == max({v[i - 1], v[i], v[i + 1]})) {
            if (i - l - 1 <= r - i - 1) {
                ans += i - l - 1;
                i++;
            }else {
                ans += r - i - 1;
                break;
            }
        }
    }

    cout << ans << '\n';
}   
    
int main ()
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