#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 a, b;
    cin >> a >> b;
    i64 l = 0, r = 2e5;
    while (l <= r) {
        i64 mid = l + (r - l) / 2;
        if (mid * mid >= a + b && max(a, b) <= mid * mid / 2 + (mid & 1)) {
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}   
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 