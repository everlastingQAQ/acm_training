#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    map <int, int> mp;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
        mx = max(mx, mp[v[i]]);
    }
    cout << n - mx << '\n';
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