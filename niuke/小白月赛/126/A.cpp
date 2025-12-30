#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    string a, b; cin >> a >> b;
    bool found1 = false, found2 = false;
    for (char c : a) {
        if (c == '+') found1 = true;
    }
    for (char c : b) {
        if (c == '+') found2 = true;
    }

    if (!found1 && !found2) {
        ll t1 = stoll(a), t2 = stoll(b);
        cout << (t1 > t2 ? "Yes" : "No") << '\n';
    }else if (!found1 && found2) {
        ll t1 = stoll(a);
        string ss = b.substr(0, b.size() - 1);
        ll t2 = stoll(ss);
        if (t1 > t2) {
            cout << "Yes" << '\n';
        }else {
            cout << "No" << '\n';
        }
    }else if (found1 && !found2) {
        string ss = a.substr(0, a.size() - 1);
        ll t1 = stoll(ss);
        ll t2 = stoll(b);
        if (t1 >= t2) {
            cout << "Yes" << '\n';
        }else {
            cout << "No" << '\n';
        }
    }else {
        string s1 = a.substr(0, a.size() - 1);
        string s2 = b.substr(0, b.size() - 1);
        ll t1 = stoll(s1);
        ll t2 = stoll(s2);
        cout << (t1 > t2 ? "Yes" : "No") << '\n';
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