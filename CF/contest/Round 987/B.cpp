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

    for (int i = 1; i <= n; i++) {
        if (v[i] != i) {
            if (abs(v[i + 1] - v[i]) == 1) {
                if (v[i + 1] != i) {
                    cout << "NO\n";
                    return;
                }else {
                    swap(v[i + 1], v[i]);
                }
            }else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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