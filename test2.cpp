#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()   
{
    int n;
    cin >> n;
    string m;
    cin >> m;
    i64 res = 0;
    for (auto c : m) {
        res = (res * 10 + c - '0') % n;
    }
    if (res == 0) {
        cout << n << '\n';
    }else {
        cout << res << '\n';
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