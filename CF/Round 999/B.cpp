#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    unordered_map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.begin(), v.end());
    int x = -1;
    for (int i = n; i >= 1; i--) {
        if (mp[v[i]] >= 2) {
            x = v[i];
            break;
        }
    }
    vector <int> a;
    for (int i = 1; i <= n; i++) {
        if (v[i] != x) {
            a.push_back(v[i]);
        }
    }

    if (mp[x] >= 4) {
        cout << x << ' ' << x << ' ' << x << ' ' << x << '\n';
        return;
    }

    if (a.size() == 0) {
        cout << -1 << '\n';
        return;
    }
    // for (int i = 0; i < a.size(); i++) {
    //     cout << a[i] << '\n';
    // }
    if (mp[x] >= 3) {
        for (int i = 0; i < a.size(); i++) {
            if (abs(x - a[i]) < 2 * x) {
                cout << x << ' ' << x << ' ' << x << ' ' << a[i] << '\n';
                return;
            }
        }
    }
    
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i + 1] - a[i] < 2 * x) {
            cout << x << ' ' << x << ' ' << a[i] << ' ' << a[i + 1] << '\n';
            return;
        }
    }
    cout << -1 << '\n';
} 
    
int32_t main ()
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