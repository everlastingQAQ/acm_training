#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    map <int, int> mp;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
        if (mp[v[i]] >= 4) {
            ok = true;
        } 
    }
    sort(v.begin() + 1, v.end());

    if (ok) {
        cout << "Yes\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (mp[v[i]] >= 2) {
            while (i < n && v[i + 1] - v[i] == 1) {
                if (mp[v[i + 1]] >= 2) {
                    cout << "Yes\n";
                    return;
                }else if (mp[v[i + 1]] == 0) {
                    break;
                }
                i++;
            }
        }
    }

    cout << "No\n";
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