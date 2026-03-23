#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 qpow (i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    i64 n;
    cin >> n;
    for (int i = 32; i >= 1; i--) {
        i64 cur = 0;
        int temp = 1;
        while (cur < n) {
            cur += qpow(temp, i);
            temp++;
        }
        if (cur == n) {
            for (int j = 1; j < temp; j++) {
                if (j < temp - 1) cout << j << "^" << i << '+';
                else cout << j << "^" << i;
            }
            return;
        }
    }
    cout << "Impossible for " << n << ".";
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