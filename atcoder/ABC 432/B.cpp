#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

string s;

void solve ()
{
    cin >> s;
    vector <ll> x(s.size());
    for (int i = 0; i < s.size(); i++) {
        x[i] = s[i] - '0';
    }
    sort(x.begin(), x.end());

    if (x[0] == 0) {
        bool found = false;
        ll pos = 0;
        for (int i = 0; i < s.size(); i++) {
            if (x[i] != 0) {
                found = true;
                pos = i;
                break;
            }
        }
        swap(x[0], x[pos]);
    }

    for (auto p : x) {
        cout << p;
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