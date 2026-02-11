#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, q;
    cin >> n >> q;
    
    int sum = 0;
    int t = 1;
    vector <int> v;
    while (sum < n) {
        v.push_back(t);
        sum += t;
        t *= 2;
    }

    int diff = sum - n;
    int m = v.size();
    v[m - 1] -= diff;

    while (q--) {
        int t;
        cin >> t;
        int h = 63 - __builtin_clzll(t);
        cout << v[h] << '\n';
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