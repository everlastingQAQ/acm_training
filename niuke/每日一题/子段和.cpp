#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1);
    map <i64, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }

    if (mp[0]) {
        cout << "NO\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (mp[-v[i]] + mp[v[i]] == n && mp[-v[i]]) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
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