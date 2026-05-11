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
    vector <i64> v(n + 1);
    i64 sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    long double t = sqrtl((q.y - p.y) * (q.y - p.y) + (q.x - p.x) * (q.x - p.x));
    if (sum < t) {
        cout << "No\n";
        return; 
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/