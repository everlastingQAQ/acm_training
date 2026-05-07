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
    vector <int> ans(n + 1);
    for (int i = n; i >= 1; i--) {
        if (v[i] == i) {
            ans[i] = i;
        }else {
            ans[i] = ans[v[i]];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}   
    
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
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