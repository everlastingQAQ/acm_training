#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> c(10);
    int mn = 1e9;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        c[t]++;
    }

    for (int i = 1; i <= 9; i++) {
        mn = min(mn, c[i]);
    }

    for (int i = 1; i <= 9; i++) {
        c[i] -= mn;
    }

    for (int i = 1; i <= 9; i++) {
        int t = c[i];
        if (t > 1) continue;
        bool ok = false;
        bool ok1 = false;
        for (int j = i; j <= 9; j++) {
            if (c[j] != 1) {
                ok1 = true;
                break;
            }
            if (ok && c[j] != 0) {
                ok1 = true;
                break;
            }
            if (c[j] != t && c[j] != 0) {
                ok1 = true;
                break;
            }else if (c[j] == 0) {
                ok = true;
            }
        }
        if (ok1) continue;
        for (int j = 1; j < i; j++) {
            if (c[j] != 1) {
                ok1 = true;
                break;
            }
            if (ok && c[j] != 0) {
                ok1 = true;
                break;
            }
            if (c[j] != t && c[j] != 0) {
                ok1 = true;
                break;
            }else if (c[j] == 0) {
                ok = true;
            }
        }
        if (ok1) continue;
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}   
    
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}