#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string a, b;
    cin >> a >> b;
    char c1 = a[0], c2 = b[0];
    a[0] = c2;
    b[0] = c1;
    cout << a << ' ' << b << '\n';
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