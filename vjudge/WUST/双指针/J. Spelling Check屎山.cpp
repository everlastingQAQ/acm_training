#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
string s1, s2;

void solve ()
{
    cin >> s1 >> s2;
    ll i = 0, j = 0;

    char c;
    ll count = 0;
    ll pos = 0;
    
    bool case1 = true;
    for (int k = 1; k < s1.size(); k++) {
        if (s1[k - 1] != s1[k]) {
            case1 = false;
            break;
        }
    }

    bool case2 = true;
    for (int k = 1; k < s2.size(); k++) {
        if (s2[k - 1] != s2[k]) {
            case2 = false;
            break;
        }
    }

    if (case1 && case2) {
        if (s1[0] == s2[0]) {
            cout << s1.size() << '\n';
            for (int k = 0; k < s1.size(); k++) {
                cout << k + 1 << ' ';
            }
            return;
        }else {
            cout << 0 << '\n';
            return;
        }
    }

    while (i < s1.size() && j < s2.size()) {
        //cout << i << ' ' << j << '\n';
        if (s1[i] != s2[j]) {
            c = s1[i];
            pos = i;
            count++;
            i++;
            if (count >= 2) {
                cout << 0 << '\n';
                return;
            }
            continue;
        }
        //cout << count << '\n';
        i++;
        if (j + 1 == s2.size()) {
            j--;
        }
        j++;
    }

    //cout << count << ' ' << i << ' ' << j << '\n';
    if (i < s1.size() && j == s2.size() - 1) {
        if (s1[i + 1] != s2[j]) {
            count++;
            
            if (count >= 2) {
                cout << 0 << '\n';
                return;
            }
        }
    }

    vector <ll> a;
    for (int i = pos - 1; i >= 0; i--) {
        if (s1[i] != c) {
            break;
        }
        a.push_back(i);
    }

    a.push_back(pos);

    for (int i = pos + 1; i < s1.size(); i++) {
        if (s1[i] != c) {
            break;
        }
        a.push_back(i);
    }

    sort(a.begin(), a.end());

    cout << a.size() << '\n';
    for (auto &i : a) {
        cout << i + 1 << ' ';
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