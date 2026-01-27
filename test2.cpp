#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 5);
    int mx = 0, p = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (mx < a[i]) {
            mx = a[i];
            p = i;
        }
    }
    int b = n;
    int p1 = 0, p2 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b) {
            p1 = i;
            break;
        }
        b--;
    }
    if (b == 0) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == b) {
            p2 = i;
            break;
        }
    }
    for (int i = 1; i < p1; i++) {
        cout << a[i] << " ";
    }
    for (int i = p2; i >= p1; i--) {
        cout << a[i] << " ";
    }
    for (int i = p2 + 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";

    // if (p == 1) {
        
    //     return ;
    // }
    // for (int i = p; i >= 1; i--) {
    //     cout << a[i] << " ";
    // }
    // for (int i = p + 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}