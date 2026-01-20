#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void Discretizate (const vector <int> &a, vector <int> &v, int n) 
{   
    vector <int> t; t = a;
    ranges::sort(t | views::drop(1));
    t.erase(unique(t.begin() + 1, t.end()), t.end());
    for (int i = 1; i <= n; i++) {
        v[i] = lower_bound(t.begin() + 1, t.end(), v[i]) - t.begin();
    }
}

void solve ()
{
    
}   
    
signed main ()
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