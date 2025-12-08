#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

bool cmp (const string &a1, const string &b1)
{
    return a1.size() <= b1.size();
}

void solve ()
{
    cin >> n;
    vector <string> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n - 1; i++) {
        if (v[i + 1].find(v[i]) == string::npos) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        cout << v[i] << '\n';
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