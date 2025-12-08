#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
int a[MAXN];

void solve ()
{
    int n;
    cin >> n;

    if (n % 2 == 1) {
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                cout << -1 << ' ';
            }else if (i % 2 == 0) {
                cout << 3 << ' ';
            }
        }
        cout << endl;
    }else {
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                cout << -1 << ' ';
            }else if (i % 2 == 0 && i != n) {
                cout << 3 << ' ';
            }else if (i == n) {
                cout << 2 << ' ';
            }
        }
        cout << endl;
    }
    
}

int main ()
{
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}