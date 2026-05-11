#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    int c0 = 0, c1 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] & 1) c1++;
        else c0++;
    }
    if (c0 >= 1) {
        cout << 1 + c1 << '\n';
    }else if (c0 == 0) {
        cout << c1 - 1 << '\n';
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