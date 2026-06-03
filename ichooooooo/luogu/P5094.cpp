
#include <bits/stdc++.h>
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
#define int long long
const int mod = 998244353;

// cnt 数目-l
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

// i pos 和-l
struct BIT2 {
    int n; 
    vector <int> bit;

    BIT2 (int x) : n (x) {
        bit.assign (n + 5, 0);
    }

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit (i)) {
            bit[i] = (bit[i] + k) % mod;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= lowbit (i)) {
            ans = (ans + bit[i]) % mod;
        }

        return ans;
    }
};

struct BIT3 {
    int n; 
    vector <int> bit;

    BIT3 (int x) : n (x) {
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

struct BIT4 {
    int n; 
    vector <int> bit;

    BIT4 (int x) : n (x) {
        bit.assign (n + 5, 0);
    }

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit (i)) {
            bit[i] = (bit[i] + k) % mod;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= lowbit (i)) {
            ans = (ans + bit[i]) % mod;
        }

        return ans;
    }
};

void ovo ()
{
    int n;
    cin >> n;
    vector <arr2> a (n);
    // x1, v1
    for (int i = 0; i < n; i ++) {
        cin >> a[i][1] >> a[i][0]; 
    }

    sort (a.begin(), a.end());

    const int N = 5e4 + 5;

    int ans = 0;
    BIT1 bit1 (N), bit2 (N), bit3 (N), bit4 (N);
    for (int i = 0; i < n; i ++) {
        int x = a[i][0], v = a[i][1];
        
        int cn = bit1.sum (x - 1) % mod;
        int sm = bit2.sum (x - 1) % mod;
        int an = v * ((cn * i % mod - sm % mod + mod) % mod) % mod;
        ans = (ans + an) % mod;

        bit1.point_add (x, 1);
        bit2.point_add (x, x);
    }

    sort (a.rbegin(), a.rend());

    for (int i = 0; i < n; i ++) {
        int x = a[i][0], v = a[i][1];
        
        int cn = bit3.sum (x - 1) % mod;
        int sm = bit4.sum (x - 1) % mod;
        int an = v * ((cn * i % mod - sm % mod + mod) % mod) % mod;
        ans = (ans + an) % mod;

        bit3.point_add (x, 1);
        bit4.point_add (x, x);
    }

    cout << ans << '\n';
} 
    
signed main ()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) ovo();
} 