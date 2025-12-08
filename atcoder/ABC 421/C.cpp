#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

ll n;
string s;

void solve ()
{
    cin >> n >> s;

    ll l = 0, r = 0;
    ll ans1 = 0;
    string s1 = s;
    // cout << s1 << '\n';

    while (l < 2 * n) {
        if (s1[l] == 'A') {
            if (l & 1) {
                if (r < l) r = l;
                while (r < 2 * n && s1[r] != 'B') {
                    r++;
                }
                ans1 += r - l;
                if (r != 2 * n) {
                    swap(s1[l], s1[r]);
                }else {
                    break;
                }
            }
        }else {
            if (!(l & 1)) {
                if (r < l) r = l;
                while (r < 2 * n && s1[r] != 'A') {
                    r++;
                }
                ans1 += r - l;
                if (r != 2 * n) {
                    swap(s1[l], s1[r]);
                }else {
                    break;
                }
            }
        }
        l++;
    }

    l = 0, r = 0;
    ll ans2 = 0;
    string s2 = s;

    while (l < 2 * n) {
        if (s2[l] == 'A') {
            if (!(l & 1)) {
                if (r < l) r = l;
                while (r < 2 * n && s2[r] != 'B') {
                    r++;
                }
                ans2 += r - l;
                if (r != 2 * n) {
                    swap(s2[l], s2[r]);
                }else {
                    break;
                }
            }
        }else {
            if (l & 1) {
                if (r < l) r = l;
                while (r < 2 * n && s2[r] != 'A') {
                    r++;
                }
                ans2 += r - l;
                if (r != 2 * n) {
                    swap(s2[l], s2[r]);
                }else {
                    break;
                }
            }
        }
        l++;
    }

    // cout << ans1 << ' ' << ans2 << '\n';

    cout << min(ans1, ans2) << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}