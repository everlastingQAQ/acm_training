#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    if (n & 1) {
        if (k & 1) {
            n -= k;
            int t = n / (k - 1);
            if (n - t * (k - 1) == 0) {
                cout << t + 1 << '\n';
            }else {
                cout << t + 2 << '\n';
            }
        }else {
            n -= k - 1;
            int t = n / k;
            if (n - t * k == 0) {
                cout << t + 1 << '\n';
            }else {
                cout << t + 2 << '\n';
            }
        }
    }else {
        if (!(k & 1)) {
            int t = n / k;
            if (n - t * k == 0) {
                cout << t << '\n';
            }else {
                cout << t + 1 << '\n';
            }
        }else {
            int t = n / (k - 1);
            if (n - t * (k - 1) == 0) {
                cout << t << '\n';
            }else {
                cout << t + 1 << '\n';
            }
        }
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