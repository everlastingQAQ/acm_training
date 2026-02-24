#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, a, b;
    cin >> n >> a >> b;

    int a1 = (n / 8) * (a + b);
    int l1 = n % 8;
    if (l1 == 7) {
        a1 += max(a, 3 * b);
    }else {
        a1 += l1 / 2 * b;
    }

    int a2 = (n / 7) * a;
    int l2 = n % 7;
    a2 += l2 / 2 * b;

    int a3 = (n / 2) * b;


    int a4 = 0;
    if (2 * (a + b) >= 8 * b) {//C > B
        int t = n / 8;
        for (int i = 0; i <= 7; i++) {
            if (t - i < 0) break;
            a4 = max(a4, (n % 8 + i * 8) / 2 * b + (t - i) * (a + b));
        }
    }else {
        a4 = a3;
    }

    int a5 = 0;
    if (7 * (a + b) >= 8 * a) {//C > A
        int t = n / 8;
        for (int i = 0; i <= 7; i++) {
            if (t - i < 0) break;
            a5 = max(a5, (n % 8 + i * 8) / 7 * a + (t - i) * (a + b));
        }
    }else {
        a5 = a2;
    }

    int a6 = 0;
    if (8 * b >= 2 * (a + b)) {//A + B > C 
        int t = n / 7;
        for (int i = 0; i <= 6; i++) {
            if (t - i < 0) break;
            a6 = max(a6, (n % 7 + i * 7) / 2 * b + (t - i) * a);
        }
    }else {//A + C > B
        int t = n / 7;
        for (int i = 0; i <= 6; i++) {
            if (t - i < 0) break;
            a6 = max(a6, (n % 7 + i * 7) / 8 * (a + b) + (t - i) * a);
        }
    }

    cout << max({a1, a2, a3, a4, a5, a6}) << '\n';

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