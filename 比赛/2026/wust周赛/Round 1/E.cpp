#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1);
    vector <int> vis(n + 1, 0);
    vector <i64> a;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] <= n) {
            if (!vis[v[i]]) {
                vis[v[i]] = true;
            }else {
                a.push_back(v[i]);
            }
        }else if (v[i] > n) {
            a.push_back(v[i]);
        }
    }    

    sort(a.begin(), a.end(), [] (auto aa, auto bb) {
        return ((aa - 1) / 2 > (bb - 1) / 2);
    });

    int cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (!vis[i]) {
            i64 t = (a[cnt] - 1) / 2;
            if (t < i) {
                cout << -1 << '\n';
                return;
            }
            cnt++;
            if (cnt == a.size()) break;
        }
    }

    cout << a.size() << '\n';
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