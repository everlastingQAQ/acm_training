#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n;

void solve ()
{
    cin >> n;
    if (n == 0) {
        cout << "Yes" << '\n';
        return;
    }
    bitset<32> a(n);

    string t = a.to_string();
    string s = t.substr(t.find('1'));

    auto check = [&] (const string &sf) {
        ll l = 0, r = sf.size() - 1;
        while (l < r) {
            if (sf[l] != sf[r]) {
                return false;
            }
            l++;
            r--;
        }
        if (sf.size() & 1) {
            return sf[sf.size() / 2] == '0';
        }else {
            return true;
        }
    };

    for (int i = s.size(); i <= 64; i++) {
        if (check(s)) {
            cout << "Yes" << '\n';
            return;
        }
        s = '0' + s;
    }

    cout << "No" << '\n';
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