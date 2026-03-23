#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

bool vis[(int)2e6 + 2];

i128 get_gcd(i128 a, i128 b) {
    return b == 0 ? a : get_gcd(b, a % b);
}

i128 get_lcm(i128 a, i128 b) {
    if (a == 0 || b == 0) return 0;
    return (a / get_gcd(a, b)) * b;
}

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    int mx = 0;
    i128 val = 1;
    bool ok = false;
    fill(vis, vis + n + m + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        vis[a[i]] = true;
        mx = max(mx, a[i]);
        if (!ok) {
            val = get_lcm(val, (__int128)a[i]);
        }
        if (val > 1e6) ok = true;
    }

    vector <int> b(m);

    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        bool ok = false;
        if (b[i] >= val && b[i] % val == 0) {
            cnt1++;
            continue;
        }
        for (int j = 1; j * j <= b[i]; j++) {
            if (b[i] % j == 0) {
                if (vis[b[i] / j]) ok = true;
                if (vis[j]) ok = true;
            }
            if (ok) break;
        }
        if (ok) cnt0++;
        else cnt2++;
    }

    // cout << cnt0 << ' ' << cnt1 << ' ' << cnt2 << '\n';

    if (cnt0 & 1) {
        if (cnt1 >= cnt2) {
            printf("Alice\n");
        }else {
            printf("Bob\n");
        }
    }else {
        if (cnt1 > cnt2) {
            printf("Alice\n");
        }else {
            printf("Bob\n");
        }
    }
}   
    
int main ()
{
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 