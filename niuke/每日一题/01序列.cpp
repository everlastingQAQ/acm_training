#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int m;
    cin >> m;
    vector <int> v(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
    }
    i64 cnt = 0;
    int n;
    cin >> n;
    int l = 1;
    while (l <= m && v[l] == 0) l++;
    int r = m;
    while (r >= l && v[r] == 0) r--;
    cnt += (l - 1) / 2;
    cnt += (m - r) / 2;

    while (l < r) {
        int p = l;
        while (l <= m && v[l] == 0) {
            l++;
        }
        cnt += (l - p - 1) / 2;
        l++;
    }

    cout << (cnt >= n ? "true\n" : "false\n");
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