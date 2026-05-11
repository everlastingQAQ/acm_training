#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int t1 = v[1], t2 = v[2];
    if (t1 & 1 == t2 & 1) {
        cout << "No" << '\n';
        return;
    }
    if (t1 & 1) {
        for (int i = 1; i <= n; i += 2) {
            if (!(v[i] & 1)) {
                cout << "No" << '\n';
                return;
            }
        }
    }else {
        for (int i = 1; i <= n; i += 2) {
            if ((v[i] & 1)) {
                cout << "No" << '\n';
                return;
            }
        }
    }
    if (t2 & 1) {
        for (int i = 2; i <= n; i += 2) {
            if (!(v[i] & 1)) {
                cout << "No" << '\n';
                return;
            }
        }
    }else {
        for (int i = 2; i <= n; i += 2) {
            if ((v[i] & 1)) {
                cout << "No" << '\n';
                return;
            }
        }
    }
    cout << "Yes" << '\n';

}   

signed main ()
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