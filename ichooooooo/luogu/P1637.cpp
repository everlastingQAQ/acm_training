
#include <bits/stdc++.h>
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
#define int long long
const int mod = 1e9 + 7;

struct BIT1 {
    int n; 
    vector <int> bit;

    BIT1 (int x) : n (x) {
        bit.assign (n + 5, 0);
    }

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit (i)) {
            bit[i] += k;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= lowbit (i)) {
            ans += bit[i];
        }

        return ans;
    }
};

struct BIT2 {
    int n; 
    vector <int> bit;

    BIT2(int x) : n (x) {
        bit.assign (n + 5, 0);
    }

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit (i)) {
            bit[i] += k;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= lowbit (i)) {
            ans += bit[i];
        }

        return ans;
    }
};


void ovo ()
{
    int n; cin >> n;
    vector <int> a (n + 1);
    
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
} 
    
signed main ()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) ovo();
} 