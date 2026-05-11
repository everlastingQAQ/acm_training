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
    for (int i = 2; i <= n; i++) {
        int t = min(v[i - 1], v[i]);
        v[i - 1] -= t;
        v[i] -= t;
    }

    if (is_sorted(v.begin() + 1, v.end())) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
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
