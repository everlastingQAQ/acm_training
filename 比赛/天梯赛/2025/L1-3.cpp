#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int mx, s, t;
    cin >> mx >> s >> t;
    if (mx >= 35 && t >= 33) {
        if (s == 1) {
            cout << "Bu Tie\n" << mx;
        }else {
            cout << "Shi Nei\n" << mx;
        }
    }else {
        if (s == 1) {
            cout << "Bu Re\n" << t;
        }else {
            cout << "Shu Shi\n" << t;
        }
    }
}   
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 