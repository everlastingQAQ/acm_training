#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 1), cnt(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    sort(v.begin() + 1, v.end());
    int mex = 0;
    for (int i = 0; i <= n + 1; i++) {
        if (!cnt[i]) {
            mex = i;
            break;
        }
    }

    i64 sum1 = 0;
    vector <int> cnt2(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        if (v[i] < mex) {
            if (cnt[v[i]] > 1) {
                v[i] = mex;
            }
        }else {
            v[i] = mex;
        } 
        sum1 += v[i];
        cnt2[v[i]]++;
    }

    i64 sum2 = 0;
    int mex2 = 0;
    for (int i = 0; i <= n + 3; i++) {
         if (!cnt2[i]) {
            mex2 = i;
            break;
        }
    }
    vector <int> cnt3(n + 5, 0);

    for (int i = 1; i <= n; i++) {
        if (v[i] < mex2) {
            if (cnt2[v[i]] > 1) {
                v[i] = mex2;
            }
        }else {
            v[i] = mex2;
        } 
        sum2 += v[i];
        cnt3[v[i]]++;
    }

    i64 sum3 = 0;
    int mex3 = 0;

    for (int i = 0; i <= n + 3; i++) {
         if (!cnt3[i]) {
            mex3 = i;
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (v[i] < mex3) {
            if (cnt3[v[i]] > 1) {
                v[i] = mex3;
            }
        }else {
            v[i] = mex3;
        } 
        sum3 += v[i];
    }

    if (k & 1) {
        if (k == 1) {
            cout << sum1 << '\n';
            return;
        }
        cout << sum3 << '\n';
    }else {
        cout << sum2 << '\n';
    }
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