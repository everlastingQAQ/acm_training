#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct BIT {
    int n;
    vector <i64> bit;

    BIT (int n = 0) {init(n);}

    void init (int m) {
        n = m;
        bit.assign(n + 1, 0);
    }

    static i64 lowbit (i64 x) { return x & -x; }

    i64 sum (int idx) const {
        i64 res = 0;
        for (; idx > 0; idx -= lowbit(idx)) res += bit[idx];
        return res; 
    }

    void point_add (int idx, i64 diff) {
        for (; idx <= n; idx += lowbit(idx)) bit[idx] += diff;
    }

    i64 point_query (int idx) const {
        return sum(idx) - sum(idx - 1);
    }
};

void solve ()
{
    
}   
    
int main ()
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