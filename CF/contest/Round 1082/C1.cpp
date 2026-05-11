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

    vector <i64> stk;
    i64 ans = 1;
    stk.push_back(v[1]);

    for (int i = 2; i <= n; i++) {
        while (stk.size() && v[i] != stk.back() + 1) {
            stk.pop_back();
        }
        if (stk.empty()) {
            ans++;
        }
        stk.push_back(v[i]);
    }
    cout << ans << '\n';
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