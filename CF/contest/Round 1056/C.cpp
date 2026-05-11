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

    for (int i = 1; i < n; i++) {
        if (abs(v[i] - v[i + 1]) >= 2) {
            cout << 0 << '\n';
            return;
        }
    }

    vector <ll> a(n + 2);
    a[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (v[i] == v[i - 1]) {
            a[i] = a[i - 1] ^ 1;
        }else {
            a[i] = a[i - 1];
        }
    }

    ll ans = 0;

    for (int k = 0; k <= 1; k++) {
        bool found = true;
        vector <ll> suml(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (a[i] == k) {
                suml[i] = suml[i - 1] + 1;
            }else {
                suml[i] = suml[i - 1];
            }   
        }

        vector<ll> sumr(n + 3, 0);
        for (int i = n; i >= 1; i--) {
            if (a[i] != k) {
                sumr[i] = sumr[i + 1] + 1;
            }else {
                sumr[i] = sumr[i + 1];
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (suml[i - 1] + sumr[i + 1] + 1 != v[i]) {
                found = false;
                break;
            }
        }

        if (found) {
            ans++;
        }
    }

    cout << ans << '\n';

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