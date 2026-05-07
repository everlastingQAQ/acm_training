#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    if (m > n - n / 2) {
        cout << "No";
    }else {
        cout << "Yes";
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