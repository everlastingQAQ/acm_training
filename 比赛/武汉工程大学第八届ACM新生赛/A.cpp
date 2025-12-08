#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll l1, l2;
string s1, s2;

void solve ()
{
    cin >> l1 >> l2 >> s1 >> s2;

    ll index = s1.find(s2);

    if (index != string::npos) {
        cout << "Yes" << '\n';
    }else {
        cout << "No" << '\n';
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