#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    if (m > (1 + n) * n / 2 + 1 || 2 * m > n) {
        cout << "NO\n";
        return;
    }
    
    int a = 1;
    int t = m;
    int sum = n;
    vector <array <int, 2> > ans;
    while (1) {
        if (sum - a < t * 2) {
            
        }
    }
}

int main ()
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