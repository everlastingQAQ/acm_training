#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n - 2 + 1);
    for (int i = 1; i <= n - 2; i++) {
        cin >> v[i];
    }
    for (int i = 2; i <= n - 2 - 1; i++) {
        if (v[i] == 0 && v[i - 1] == 1 && v[i + 1] == 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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