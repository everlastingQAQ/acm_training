#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct point {
    i64 x, y;
};

void solve ()
{
    int n;
    cin >> n;
    point p, q;
    cin >> p.x >> p.y >> q.x >> q.y;
    double sum = 0;
    vector <double> v(n + 1);
    v[0] = sqrtl((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    sum += 1.0 * sqrtl((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));

    for (int i = 0; i <= n; i++) {
        if (v[i] > sum - v[i]) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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