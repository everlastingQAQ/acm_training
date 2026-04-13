#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <i64> a(n + m + 2), b(n + m + 2);
    for (int i = 1; i <= n + m + 1; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n + m + 1; i++) {
        cin >> b[i];
    }
    vector <int> v(n + m + 2, 0);
    int c1 = 0, c2 = 0;
    i64 res = 0;

    for (int i = 1; i <= n + m; i++) {
        if (c1 == n) {
            res += b[i];
            if (a[i] > b[i]) v[i] = 4;//被动B
            else v[i] = 2;//主动B 
            c2++;
        }else if (c2 == m) {
            res += a[i];
            if (b[i] > a[i]) v[i] = 3;//被动A
            else v[i] = 1;//主动A
            c1++;
        }else {
            if (a[i] > b[i]) {
                res += a[i];
                v[i] = 1;//主动A
                c1++;
            }else {
                res += b[i];
                v[i] = 2;//主动B
                c2++;
            }
        }
    }

    vector <array <i64, 2> > aa(n + m + 2, {-1, -1}), bb(n + m + 2, {-1, -1});

    for (int i = n + m; i >= 1; i--) {
        if (i < n + m) {
            aa[i][0] = aa[i + 1][0];
            aa[i][1] = aa[i + 1][1];
            bb[i][0] = bb[i + 1][0];
            bb[i][1] = bb[i + 1][1];
        }
        
        if (v[i] == 3) {
            aa[i][0] = i;
            aa[i][1] = b[i] - a[i];
        }else if (v[i] == 4) {
            bb[i][0] = i;
            bb[i][1] = a[i] - b[i];
        }
    }

    vector <i64> ans(n + m + 2);
    ans[n + m + 1] = res;

    for (int i = 1; i <= n + m + 1; i++) {
        i64 cur = res;
        if (v[i] == 1 || v[i] == 3) {
            cur -= a[i];
            if (bb[i + 1][0] != -1) {
                cur += bb[i + 1][1];
                cur += b[n + m + 1];
            }else {
                cur += a[n + m + 1];
            }
        }else if (v[i] == 2 || v[i] == 4) {
            cur -= b[i];
            if (aa[i + 1][0] != -1) {
                cur += aa[i + 1][1];
                cur += a[n + m + 1];
            }else {
                cur += b[n + m + 1];
            }
        }
        cout << cur << ' ';
    }
    cout << '\n';
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