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

string s;

void solve ()
{
    cin >> s;
    if (s == "red") {
        cout << "SSS" << '\n';
    }else if (s == "blue") {
        cout << "FFF" << '\n';
    }else if (s == "green") {
        cout << "MMM" << '\n'; 
    }else {
        cout << "Unknown" << '\n';
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