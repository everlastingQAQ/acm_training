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

ll q;

void solve ()
{
    cin >> q;
    vector <ll> a{0};
    vector <ll> b{0};
    int d;
    char c;

    for (int i = 0; i < q; i++) {
        cin >> d;
        ll t = 0;
        if (d == 1) {
            cin >> c;
            if (c == '(') {
                t = 1;
            }else {
                t = -1;
            }
            a.emplace_back(a.back() + t);
            b.emplace_back(min(b.back(), a.back()));

        }else {
            a.pop_back();
            b.pop_back();
        }

        if (a.back() == 0 && b.back() == 0) {
            cout << "Yes" << '\n';
        }else {
            cout << "No" << '\n';
        }
    }

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