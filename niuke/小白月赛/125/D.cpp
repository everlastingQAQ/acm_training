#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
    
ll n;

void solve ()
{
    cin >> n;
    string s = to_string(n);
    bool found = false;
    ll sum = 0;
    for (char c : s) {
        sum += c - '0';
        if (c != '9') {
            found = true;
        }
    }

    if (!found) {
        cout << 0 << '\n';
        return;
    }

    if (sum % 9 == 0) {
        ll tag = pow(10, s.size()) - 1;
        cout << (tag - n) / 9 << '\n';
        return;
    }

    bool found1 = true;
    for (char c : s) {
        if (c != '1') {
            found1 = false;
            break;
        }
    }


    if (found1) {
        cout << 1 << '\n';
        return;
    }

    ll t = s.size();
    if (t == 1) {
        if (n == 2) {
            cout << 2 << '\n';
        }else {
            cout << 12 - n << '\n';
        }
        return;
    }

    if (t == 2) {
        if (n <= 11) {
            if (n == 10) cout << 2 << '\n';
            return;
        }else {
            ll ans = 0;
            ll temp = (109 - n) / 9;
            ans += temp;
            n += temp * 9;
            string ss = to_string(n);
            if (ss[ss.size() - 1] == '2') {
                cout << ans + 2 << '\n';
                return;
            }else if (ss[ss.size() - 1] == '1') {
                cout << ans + 3 << '\n';
                return;
            }
            ans += 12 - (ss[ss.size() - 1] - '0');
            cout << ans << '\n';
        }
    }else {
        ll j = t - 1;
        ll tag = 9;
        while (j >= 2) {
            tag += pow(10, j);
            j--;
        }
        ll ans = 0;
        if (n <= tag) {
            ll temp = (tag - n) / 9;
            ans += temp;
            n += temp * 9;
            string ss = to_string(n); 
            if (ss[ss.size() - 1] == '2') {
                cout << ans + 2 << '\n';
                return;
            }else if (ss[ss.size() - 1] == '1') {
                cout << ans + 3 << '\n';
                return;
            }
            ans += 12 - (ss[ss.size() - 1] - '0');
        }else {
            tag += pow(10, t);
            ll temp = (tag - n) / 9;
            ans += temp;
            n += temp * 9;
            string ss = to_string(n);
            if (ss[ss.size() - 1] == '2') {
                cout << ans + 2 << '\n';
                return;
            }else if (ss[ss.size() - 1] == '1') {
                cout << ans + 3 << '\n';
                return;
            }
            ans += 12 - (ss[ss.size() - 1] - '0');
        }
        cout << ans << '\n';
    }
   
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