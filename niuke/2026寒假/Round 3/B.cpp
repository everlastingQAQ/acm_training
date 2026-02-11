#include <bits/stdc++.h>
using namespace std;
#define int long long

const int t = 1e9;

void solve ()
{
    mt19937 rd(time(0));
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= 500; i++) {
        int a = rd() % n + 1;
        int b = rd() % n + 1;
        if (a == b) continue;
        if (gcd(v[a], v[b]) != 1) {
            cout << v[a] << ' ' << v[b] << '\n';
            return;
        }
    }

    cout << -1 << '\n';
    
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