#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end(), greater<>());
    
    vector <i64> ans(2 * n + 3);
    ans[1] = v[1];
    int pos = 2;

    for (int i = 3; i <= 2 * n + 1; i += 2) {
        ans[i] = v[pos++];
    }
    for (int i = 4; i <= 2 * n + 1; i += 2) {
        ans[i] = v[pos++];
    }

    i64 cur = ans[1];
    for (int i = 3; i <= 2 * n + 1; i++) {
        if (i & 1) cur += ans[i];
        else cur -= ans[i];
    } 
    
    ans[2] = cur; 
    // cout << cur << ' ';
    for (int i = 1; i <= 2 * n + 1; i++) {
        cout << ans[i] << " \n"[i == 2 * n + 1];
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