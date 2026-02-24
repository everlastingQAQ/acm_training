#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n;
    cin >> n;
    vector <i64> v(2 * n + 1);
    map <i64, int> mp;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> v[i];
        mp[v[i]] = 1;
    }
    sort(v.begin() + 1, v.end());
    vector <i64> ans(2 * n + 2);
    int idx = 1;
    int t1 = 0, t2 = 0;
    for (int i = 1; i <= 2 * n; i += 2) {
        ans[i] = v[idx++];
        t1 += ans[i];
    }
    for (int i = 2; i <= 2 * n; i += 2) {
        ans[i] = v[idx++];
        t2 += ans[i];
    }

    i64 t = t2 - t1;
    int idx = 1
    while (mp[t]) { 
        
    }

    for (int i = 1; i <= 2 * n + 1; i++) {
        cout << ans[i] << " \n"[i == 2 * n + 1];
    }
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/