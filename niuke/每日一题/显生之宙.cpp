#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());
    vector <i64> d(n + 2);
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        v[i] += d[i];
        if (v[i] < 0) {
            d[i + 1] += v[i];
            d[n + 1] -= v[i]; 
        }else {
            d[i + 1] += v[i];
            d[i + 2] -= v[i];
        }
    }

    cout << v[n] << '\n';
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