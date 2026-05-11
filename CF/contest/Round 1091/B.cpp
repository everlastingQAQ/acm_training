#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int p;
    cin >> p;
    int c1 = 0;
    for (int i = p + 1; i <= n; i++) {
        if (v[i] != v[i - 1]) c1++;
    }
    int c2 = 0;
    for (int i = p - 1; i >= 1; i--) {
        if (v[i] != v[i + 1]) c2++;
    }
    if (c1 < c2) swap(c1, c2);
    if (c1 & 1) c1++;
    cout << c1 << '\n';
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