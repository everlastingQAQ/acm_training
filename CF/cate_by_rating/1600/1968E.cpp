#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    if (n == 2) {
        cout << "1 1\n1 2\n\n";
    }else if (n == 3) {
        cout << "2 1\n2 3 \n3 1\n\n";
    }else if (n == 4) {
        cout << "1 1\n1 3 \n4 3\n4 4\n\n";
    }else if (n == 5) {
        cout << "1 1\n1 3\n1 4\n2 1\n5 5\n\n";
    }else {
        cout << "1 1\n1 2\n2 3\n";
        for (int i = 4; i <= n; i++) {
            cout << i << ' ' << i << '\n';
        }
        cout << '\n';
    }
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