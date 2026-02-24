#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1), a(n + 1);
    vector <i64> vv(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> vv[i];
        v[i] = vv[i];
        a[i] = v[i];
        if (a[i] & 1) a[i]++;
        a[i] /= 2;
        v[i] /= 2;
    }

    vector <i64> sufv(n + 2), sufa(n + 2);
    sufv[n] = v[n], sufa[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        sufv[i] = sufv[i + 1] + v[i];
        sufa[i] = sufa[i + 1] + a[i];
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vv[i] & 1) {
            i64 cur = v[i] * (n - i);
            cur += sufa[i + 1];
            ans += cur;
        }else {
            i64 cur = v[i] * (n - i);
            cur += sufv[i + 1];
            ans += cur;
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/