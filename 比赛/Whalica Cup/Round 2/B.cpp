#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    cout << "YES\n";
    int t = n / 2;
    vector <int> v(n + 1);
    int cur = 1;
    for (int i = 2; i <= n; i += 2) {
        v[i] = cur;
        cur++;
    }

    for (int i = 1; i <= n; i += 2) {
        v[i] = cur;
        cur++;
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i] << " \n"[i == n];
    }
}   
    
int32_t main ()
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