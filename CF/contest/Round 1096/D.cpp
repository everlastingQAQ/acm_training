#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(2 * n + 1);
    vector <array <int, 2> > pos(n + 1, {-1, -1});
    for (int i = 1; i <= 2 * n; i++) {
        cin >> v[i];
        if (pos[v[i]][0] != -1) {
            pos[v[i]][1] = i;
        }else {
            pos[v[i]][0] = i;
        }
    }

    int a1 = 1;
    int l = pos[0][0] - 1, r = pos[0][0] + 1;
    map <int, int> mp1;
    while (l >= 1 && r <= 2 * n) {
        if (v[l] != v[r]) {
            break;
        }
        mp1[v[l]] = true;
        while (mp1[a1]) {
            a1++;
        }
        l--;
        r++;
    }

    int a2 = 1;
    l = pos[0][1] - 1, r = pos[0][1] + 1;
    map <int, int> mp2;
    while (l >= 1 && r <= 2 * n) {
        if (v[l] != v[r]) {
            break;
        }
        mp2[v[l]] = true;
        while (mp2[a2]) {
            a2++;
        }
        l--;
        r++;
    }

    int ans = max(a1, a2);

    int a3 = 1;
    l = pos[0][0], r = pos[0][1];
    map <int, int> mp3;
    bool ok = true;
    while (l <= r) {
        if (v[l] != v[r]) {
            ok = false;
            break;
        }
        mp3[v[l]] = true;
        while (mp3[a3]) {
            a3++;
        }
        l++;
        r--;
    }

    if (ok) {
        l = pos[0][0] - 1, r = pos[0][1] + 1;
        // cout << l << ' ' << r << '\n';
        while (l >= 1 && r <= 2 * n) {
            if (v[l] != v[r]) {
                break;
            }
            mp3[v[l]] = true;
            while (mp3[a3]) {
                a3++;
            }
            l--;
            r++;
        }
        ans = max(ans, a3);
    }

    cout << ans << '\n';
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