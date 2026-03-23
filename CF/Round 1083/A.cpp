#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, v[i]);
        if (mx <= i) {
            int mxx = 0;
            int pos = 0;
            for (int j = n; j > i; j--) {
                if (v[j] > mxx) {
                    pos = j;
                    mxx = v[j];
                }
            }
            if (pos != 0) swap(v[pos], v[i]);
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i] << " \n"[i == n];
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