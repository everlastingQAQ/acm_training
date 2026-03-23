#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1);
    map <i64, int> mp;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[(v[i] ^ i)]++;
        mx = max(mx, mp[(v[i] ^ i)]);
    }
    cout << n - mx << '\n';
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