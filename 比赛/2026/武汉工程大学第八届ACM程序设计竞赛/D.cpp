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
    int cnt = 0;    
    for (int i = 2; i <= n; i++) {
        if (v[i] >= v[1]) {
            cnt++;
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        if (v[i] <= v[n]) {
            cnt++;
            break;
        }
    }
    cout << (cnt <= 1 ? "YES\n" : "NO\n");
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