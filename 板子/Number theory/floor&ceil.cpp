#include <bits/stdc++.h>
using namespace std;
#define int long long

int Floor (int a, int b) {
    if (a >= 0) return a / b;
    return -((-a + b - 1) / b);
}

int Ceil (int a, int b) {
    return -Floor(-a, b);
}

void solve ()
{
    
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