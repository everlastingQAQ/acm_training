#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 1), b(m + 1);
    int suma = 0, sumb = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        suma += a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        sumb += b[i];
    }

    
    if (suma > sumb) {
        ranges::sort(a | views::drop(1));
        int cnt = 0;
        for (int i = n; i >= 1; i--) {
            suma -= a[i];
            cnt++;
            if (sumb >= suma) {
                break;
            }
        }
        cout << cnt << '\n';
    }else if (suma == sumb) {
        cout << 1 << '\n';
    }else {
        ranges::sort(b | views::drop(1));
        int cnt = 0;
        for (int i = m; i >= 1; i--) {
            sumb -= b[i];
            cnt++;
            if (suma >= sumb) {
                break;
            }
        }
        cout << cnt << '\n';
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