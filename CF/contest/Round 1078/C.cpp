#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <string> s(k);
    for (string &x : s) cin >> x;

    vector <vector <int> > vis(n + 1, vector <int> (26, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            vis[i][s[j][i] - 'a']++;
        }
    }

    for (int len = 1; len <= n; len++) {
        if (n % len) continue;
        int cnt = 0;
        vector <char> t(len);
        for (int i = 0; i < len; i++) {
            bool ok1 = true;
            for (int j = 0; j < k; j++) {
                bool ok2 = true;
                int tt = s[j][i] - 'a';
                for (int l = i + len; l < n; l += len) {
                    if (!vis[l][tt]) {
                        ok2 = false;
                        break;
                    }
                }
                if (ok2) {
                    t[cnt++] = tt + 'a';
                    break;
                }else if (!ok2 && j == k - 1) {
                    ok1 = false;
                    break;
                }
            }
            if (!ok1) {
                break;
            }else if (ok1 && i == len - 1) {
                for (int j = 0; j < n / len; j++) {
                    for (char c : t) {
                        cout << c;
                    }
                }
                cout << '\n';
                return;
            }
        }
    }
}   
    
int32_t main ()
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/