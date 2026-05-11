#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <array <int, 3> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    sort(v.begin() + 1, v.end());
    sort(v.begin() + 1, v.begin() + 1 + n / 2, [] (auto a, auto b) {
        return a[1] > b[1]; 
    });
    sort(v.begin() + 1 + n / 2, v.end(), [] (auto a, auto b) {
        return a[1] > b[1]; 
    });

    for (int i = 1; i <= n / 2; i++) {
        cout << v[i][2] << ' ' << v[n - i + 1][2] << '\n';
    }
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