#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, h;
    cin >> n >> h;
    int mx = -1;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    int ans = n * (h - mx);
    // cout << ans << '\n';
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = mx - v[i];
        cout << a[i] << " \n"[i == n];
    }
    int ans1 = -1;
    cout << mx << '\n';
    vector <int> diff(n + 1);
    for (int i = 1; i <= n; i++) {
        int l = i - 1, r = i + 1;
        int cur = a[i];
        int mxx = v[i];
        vector <int> t(n + 1);
        t[i] = a[i];
        while (l >= 1) {
            if (v[l] == mx) {
                break;
            }
            if (v[l] >= mxx) {
                cur += a[l];
                t[l] = a[l];
            }else {
                cur += mx - mxx;
                mxx = max(mxx, v[l]);
                t[l] = mx - mxx;
            }
            mxx = max(mxx, v[l]);
            l--;
        }
        cout << i << ' ' << cur << '\n';
        mxx = v[i];
        while (r <= n) {
            // cout << i << ' ' << r << ' ' << mxx << '\n';
            if (v[r] == mx) {
                break;
            }
            if (v[r] >= mxx) {
                cur += a[r];
                t[r] = a[r];
            }else {
                cur += mx - mxx;
                mxx = max(mxx, v[r]);
                t[r] = mx - mxx;
            }
            mxx = max(mxx, v[r]);
            r++;
        }
        // cout << i << ' ' << cur << '\n';
        if (cur > ans1) {
            diff = t;   
            ans1 = cur;
        }
    }
    cout << ans1 << '\n';
    for (int i = 1; i <= n; i++) {
        a[i] -= diff[i];
        cout << a[i] << " \n"[i == n];
    }

    int ans2 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) continue;
        int l = i - 1, r = i + 1;
        int cur = a[i];
        int mxx = v[i];
        while (l >= 1) {
            if (v[l] == mx || a[l] == 0) {
                break;
            }
            if (v[l] >= mxx) {
                cur += a[l];
            }else {
                cur += mx - mxx;
                mxx = max(mxx, v[l]);
            }
            mxx = max(mxx, v[l]);
            l--;
        }
        mxx = v[i];
        while (r <= n) {
            // cout << i << ' ' << r << ' ' << mxx << '\n';
            if (v[r] == mx || a[r] == 0) {
                break;
            }
            if (v[r] >= mxx) {
                cur += a[r];
            }else {
                cur += mx - mxx;
                mxx = max(mxx, v[r]);
            }
            mxx = max(mxx, v[r]);
            r++;
        }
        ans2 = max(ans2, cur);
    }
    // cout << ans2 << '\n';

    cout << ans2 + ans1 + ans << '\n';
    // cout << 999 << '\n';
}   
    
int32_t main ()
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