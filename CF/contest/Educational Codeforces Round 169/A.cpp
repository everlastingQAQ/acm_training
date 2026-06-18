#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    if (n > 2 || (n == 2 && v[2] - v[1] == 1)) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
    }
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