#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, k;
    cin >> n >> k;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());
    for (int i = 2; i <= n; i++) {
        int t = v[i] ^ v[i - 1];
        if (t <= k) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
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