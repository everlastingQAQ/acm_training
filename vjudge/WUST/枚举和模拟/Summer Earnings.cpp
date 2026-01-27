#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int N = 3001;

void solve ()
{
    int n; cin >> n;
    vector <int > x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    vector <array<int, 3> > v;
    int m = n * (n - 1) / 2;
    v.reserve(m);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]); 
            v.push_back({i, j, d});
        }
    }

    ranges::sort(v, [] (auto a1, auto b1) {
        return a1[2] > b1[2];
    });

    static bitset <N> bit[N];

    for (int i = 0; i < m; i++) {
        if ((bit[v[i][0]] & bit[v[i][1]]).any()) {
            cout << fixed << setprecision(6) << sqrt((ld)v[i][2]) / (ld)2.0 << '\n';
            return;
        }
        bit[v[i][0]].set(v[i][1]);
        bit[v[i][1]].set(v[i][0]);
    }
}   
    
signed main ()
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