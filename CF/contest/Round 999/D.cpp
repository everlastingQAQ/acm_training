#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <i64> a(n + 1);
    map <i64, int> mpa;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mpa[a[i]]++;
    }
    vector <i64> b(m + 1);
    map <i64, int> mpb;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        mpb[b[i]]++;
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