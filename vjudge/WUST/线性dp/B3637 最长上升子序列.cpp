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
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <ll> f(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (v[i] > v[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }

    cout << *max_element(f.begin() + 1, f.end()) << '\n';
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