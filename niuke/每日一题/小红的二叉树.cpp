#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int qpow (int a, int b)//a的b次方
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return;
    }else if (n == 2) {
        cout << 1;
        return;
    }
    vector <int> v(n + 1);
    v[1] = 0;
    v[2] = 1;
    for (int i = 3; i <= n; i++) {
        v[i] = (v[i - 1] + (qpow(2, i - 2) * 3) % mod) % mod;
    }
    cout << v[n];
}   
    
int32_t main ()
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