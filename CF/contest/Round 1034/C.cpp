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
    vector <int> premn(n + 1), sufmx(n + 1);
    premn[1] = v[1];
    sufmx[n] = v[n];
    for (int i = 2; i <= n; i++) {
        premn[i] = min(premn[i - 1], v[i]);
    }
    for (int i = n - 1; i >= 1; i--) {
        sufmx[i] = max(sufmx[i + 1], v[i]);
    }

    cout << 1;
    for (int i = 2; i <= n - 1; i++) {
        int mn = premn[i - 1];
        int mx = sufmx[i + 1];
        if (v[i] > mx || v[i] < mn) {
            cout << 1;
        }else {
            cout << 0;
        }
    }
    cout << 1;
    cout << '\n';
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