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
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
            if (i - 1 >= 0 && (s[i - 1] == '>' || s[i - 1] == '*')) {
                cout << -1 << '\n';
                return;
            }
            if (i + 1 < s.size() && (s[i + 1] == '<' || s[i + 1] == '*')) {
                cout << -1 << '\n';
                return;
            }
        }else if (s[i] == '>') {
            if (i + 1 < s.size()) {
                if (s[i + 1] == '<') {
                    cout << -1 << '\n';
                    return;
                }
            }
        }else if (s[i] == '<') {
            if (i - 1 >= 0) {
                if (s[i - 1] == '>') {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }

    if (s[0] == '*' && s.size() == 1) {
        cout << 1 << '\n';
        return;
    }

    vector <char> stk;
    vector <ll> time;

    ll cnt;
    if (s[0] == '*') {
        cnt = 2;
    }else {
        cnt = 1;
    }
    for (int i = 0; i < s.size(); i++) {
        if (stk.empty()) {
            if (s[i] != '*') {
                stk.emplace_back(s[i]);
            }else {
                continue;
            }
            continue;
        }
        if (stk.back() == '<') {
            if (s[i] == '<') {
                cnt++;
            }else if (s[i] == '>') {
                time.emplace_back(cnt);
                stk.pop_back();
                stk.emplace_back(s[i]);
                cnt = 1;
            }else if (s[i] == '*') {
                time.emplace_back(cnt + 1);
                stk.pop_back();
                cnt = 2;
            }
        }else if (stk.back() == '>') {
            if (s[i] == '>') {
                cnt++;
            }else if (s[i] == '<') {
                time.emplace_back(cnt);
                stk.pop_back();
                stk.emplace_back(s[i]);
                cnt = 1;         
            }else if (s[i] == '*') {
                time.emplace_back(cnt + 1);
                stk.pop_back();
                cnt = 2;
            }
            
        }
        
    }

    time.emplace_back(cnt);

    // for (auto x : time) {
    //     cout << x << ' ';
    // }
    ll ans = *max_element(time.begin(), time.end());

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