#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 2; i < n; i++) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            cout << "No\n";
            return;
        }
    }   
    if (v[1] > v[2] || v[n] > v[n - 1]) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

int main ()
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