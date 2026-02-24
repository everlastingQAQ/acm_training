#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int pa = 1, pb = 1;
    while (pb <= n) {
        // cout << pb << ' ' << pa << '\n';
        int cur = b[pb];
        while (pa <= n && a[pa] != cur) {
            pa++;
        }
        // cout << pb << ' ' << pa << '\n';
        if (pa == n + 1 && pb <= n) {
            cout << "NO\n";
            return;
        }

        while (pb <= n && b[pb] == cur) {
            if (b[pb] != cur) {
                cout << "NO\n";
                return;
            }
            pb++;
        }
        pa++;
    }

    // cout << pb << ' ' << pa << '\n';

    // if (pb != n + 1) {
        // cout << "NO\n";
    // }else {
        cout << "YES\n";
    // }
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/