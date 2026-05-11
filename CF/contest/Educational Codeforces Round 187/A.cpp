#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m, d;
    cin >> n >> m >> d;
    if (m > d) {
        cout << n << '\n';
        return;
    }

    int t = d / m;
    t += 1;
    int tt = n / t;
    if (n % t) tt++;
    cout << tt << '\n';
}   
    
int main ()
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