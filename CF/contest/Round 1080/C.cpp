#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (v[i] + v[i - 1] == 7 || v[i] == v[i - 1]) {
            ans++;
            if (i != n) {
                int t = v[i + 1];
                for (int j = 1; j <= 6; j++) {
                    if (j == t || j == v[i - 1]) continue;
                    if (j + t == 7 || j + v[i - 1] == 7) continue;
                    v[i] = j;
                    break;
                }
            }else {
                for (int j = 1; j <= 6; j++) {
                    if (j == v[i - 1]) continue;
                    if (j + v[i - 1] == 7) continue;
                    v[i] = j;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
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