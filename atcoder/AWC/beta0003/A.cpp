#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        i64 a, b;
        cin >> a >> b;
        if (a * b >= k) {
            cnt++;
        }
    }
    cout << cnt << '\n';
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