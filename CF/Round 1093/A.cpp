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
    sort(v.begin() + 1, v.end(), greater<>());
    map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        if (mp[v[i]]) {
            cout << "-1\n";
            return;
        }else {
            mp[v[i]] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << v[i] << " \n"[i == n];
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