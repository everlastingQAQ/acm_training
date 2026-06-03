#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <int> a, b;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == 'B') b.push_back(v[i]);
        else a.push_back(v[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ia = 0, ib = 0;
    for (int i = 1; i <= n; i++) {
        // cout << ib << ' ' << ia << '\n';
        if (ib < b.size() && b[ib] >= i) ib++;
        else {
            if (ia == a.size() || a[ia] > i) {
                cout << "NO\n";
                return;
            }
            ia++;
        }
    }
    cout << "YES\n";
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