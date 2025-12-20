#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{
    string s; cin >> s;
    vector <ll> cnt(5, 0);
    ll n = s.size();

    for (ll i = 0; i < n; i++) {
        if (s[i] == 'C') {
            for (ll j = i + 1; j < n; j++) {
                if (s[j] == 'C') {
                    for (ll k = j + 1; k < n; k++) {
                        if (s[k] == 'N') {
                            for (ll l = k + 1; l < n; l++) {
                                if (s[l] == 'U') cnt[0]++;
                            }
                        }
                    }
                }
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        if (s[i] == 'H') {
            for (ll j = i + 1; j < n; j++) {
                if (s[j] == 'U') {
                    for (ll k = j + 1; k < n; k++) {
                        if (s[k] == 'S') {
                            for (ll l = k + 1; l < n; l++) {
                                if (s[l] == 'T') cnt[1]++;
                            }
                        }
                    }
                }
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        if (s[i] == 'H') {
            for (ll j = i + 1; j < n; j++) {
                if (s[j] == 'Z') {
                    for (ll k = j + 1; k < n; k++) {
                        if (s[k] == 'A') {
                            for (ll l = k + 1; l < n; l++) {
                                if (s[l] == 'U') cnt[2]++;
                            }
                        }
                    }
                }
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        if (s[i] == 'W') {
            for (ll j = i + 1; j < n; j++) {
                if (s[j] == 'H') {
                    for (ll k = j + 1; k < n; k++) {
                        if (s[k] == 'U') {
                            for (ll l = k + 1; l < n; l++) {
                                if (s[l] == 'T') cnt[4]++;
                            }
                        }
                    }
                }
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        if (s[i] == 'W') {
            for (ll j = i + 1; j < n; j++) {
                if (s[j] == 'H') {
                    for (ll k = j + 1; k < n; k++) {
                        if (s[k] == 'U') cnt[3]++; 
                    }
                }
            }
        }
    }

    if (cnt[0] == max({cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]})) {
        cout << "CCNU " << cnt[0] << '\n';
    }else if (cnt[1] == max({cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]})) {
        if (cnt[0] == cnt[1]) {
            cout << "CCNU " << cnt[0] << '\n';
        }else {
            cout << "HUST " << cnt[1] << '\n';
        }
    }else if (cnt[2] == max({cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]})) {
        if (cnt[0] == cnt[2]) {
            cout << "CCNU " << cnt[0] << '\n';
        }else if (cnt[1] == cnt[2]) {
            cout << "HUST " << cnt[1] << '\n';
        }else {
            cout << "HZAU " << cnt[2] << '\n';
        }
    }else if (cnt[3] == max({cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]})) {
        if (cnt[0] == cnt[3]) {
            cout << "CCNU " << cnt[0] << '\n';
        }else if (cnt[1] == cnt[3]) {
            cout << "HUST " << cnt[1] << '\n';
        }else if (cnt[2] == cnt[3]) { 
            cout << "HZAU " << cnt[2] << '\n';
        }else {
            cout << "WHU " << cnt[3] << '\n';
        }
    }else if (cnt[4] == max({cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]})) {
        if (cnt[0] == cnt[4]) {
            cout << "CCNU " << cnt[0] << '\n';
        }else if (cnt[1] == cnt[4]) {
            cout << "HUST " << cnt[1] << '\n';
        }else if (cnt[2] == cnt[4]) { 
            cout << "HZAU " << cnt[2] << '\n';
        }else if (cnt[3] == cnt[4]) {
            cout << "WHU " << cnt[3] << '\n';
        }else {
            cout << "WHUT " << cnt[4] << '\n';
        }
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}   