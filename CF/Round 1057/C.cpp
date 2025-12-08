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

void solve ()//WA3
{
    cin >> n;
    if (n == 3) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a + b <= c || a + c <= b || b + c <= a) {
            cout << 0 << '\n';
            return;
        }
        if (a == b || a == c || b == c) {
            cout << a + b + c << '\n';
            return;
        }else {
            cout << 0 << '\n';
            return;
        }
    }

    map <ll, ll> mp;
    set <ll> st;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        mp[t]++;
        st.insert(t);
    }

    ll ans = 0;
    ll cnt = 0;
    vector <ll> v;
    for (auto it = st.begin(); it != st.end(); it++) {
        if (mp[*it] >= 2) {
            cnt++;
            if (mp[*it] & 1) {
                ans += *it * (mp[*it] - 1);
                v.push_back(*it);
            }else {
                ans += *it * mp[*it];
            }
        }else {
            v.push_back(*it);
        }
    }

    sort(v.begin(), v.end(), greater<ll> ());

    if (v.size() >= 2) {
        bool found = false;
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] - v[i + 1] < ans) {
                found = true;
                ans += v[i] + v[i + 1];                     
                break;
            }
        }
        if (!found) {
            // for (int i = 0; i < v.size() - 1; i++) {
            //     if (v[i] < ans) {
            //         ans += v[i];
            //         break;
            //     }
            // }
            ans += v[1];
        }
    }else if (v.size() == 1) {
        ans += v[0];
    }

    if (!(cnt)) {
        cout << "0" << '\n';
    }else {
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