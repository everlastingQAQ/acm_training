#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, char>;

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
    s = ' ' + s;

    vector <ll> v;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            v.push_back(i);
        }
    } 

    if (v.size() == n - 1) {
        cout << "No" << '\n';
        return;
    }
    if (s[n] == '0' && s[n - 1] == '1') {
        cout << "No" << '\n';
        return;
    }
    if (s[2] == '1' && s[1] == '0') {
        cout << "No" << '\n';
        return;
    }

    if (v.size() != 0) {
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i + 1] - v[i] == 2) {
                cout << "No" << '\n';
                return;
            }
        }
    }

    cout << "Yes" << '\n';

    vector <ll> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
    }

    if (v.size() == 1) {
        if (v[0] == 1) {
            reverse(ans.begin() + 2, ans.end());
        }else {
            reverse(ans.begin() + 1, ans.begin() + 1 + v[0] - 1);
            reverse(ans.begin() + v[0] + 1, ans.end());
        }
    }else if (v.size() == 0) {
        reverse(ans.begin() + 1, ans.end());
    }else {
        if (v[0] != 1) {
            reverse(ans.begin() + 1, ans.begin() + 1 + v[0] - 1);
        }
        ll l = 1, r = 1;
        for (int i = 1; i < v.size(); i++) {
            l = v[i - 1] + 1;
            r = v[i] - 1;
            ll t = r;
            for (int i = l; i <= r; i++) {
                ans[i] = r - i + l;
            }
        }
        if (s[n] != '1') {
            reverse(ans.begin() + v[v.size() - 1] + 1, ans.end());
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
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