#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
    cin >> n;
    vector <array <int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                i64 c1 = (v[j][1] - v[i][1]) * (v[k][0] - v[j][0]);
                i64 c2 = (v[k][1] - v[j][1]) * (v[j][0] - v[i][0]);
                if (c1 == c2) {
                    cout << "Yes\n";
                    return;
                }
            }
        } 
    }
    cout << "No\n";
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}