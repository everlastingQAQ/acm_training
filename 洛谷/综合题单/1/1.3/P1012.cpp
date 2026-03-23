#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <string> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    auto cmp = [&] (string a, string b) -> bool {
        return a + b > b + a;
    };

    sort(v.begin() + 1, v.end(), cmp);
    for (int i = 1; i <= n; i++) {
        cout << v[i];
    }
} 
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 