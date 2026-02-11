#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt;
int N;

void solve ()
{
    int n, a, b;
    cin >> n >> a >> b;
    int t = gcd(a, b);
    int tt = n / t;
    if (tt & 1) {
        cout << "Case #" << N - cnt << ": Yuwgna\n";
    }else {
        cout << "Case #" << N - cnt << ": Iaka\n";
    }
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int _ = 1;
    // cin >> _;
    // while (_--) {
    //     solve();
    // }
    cin >> cnt;
    N = cnt;
    while (cnt--) {
        solve();
    }
    return 0;
} 

/*
  /\_/\
 (= ._.)
 / >  \>
*/