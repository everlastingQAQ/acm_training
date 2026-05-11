#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void solve ()
{
    int n; cin >> n;
    vector <int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    if (a[n - 1] != b[n - 1]) {
        cout << "No" << '\n';
        return;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != b[i]) {
            if ((a[i] ^ a[i + 1]) != b[i] && (a[i] ^ b[i + 1]) != b[i]) {
                cout << "No" << '\n';
                return;
            }
        }
    }

    cout << "Yes" << '\n';
}   
    
signed main ()
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