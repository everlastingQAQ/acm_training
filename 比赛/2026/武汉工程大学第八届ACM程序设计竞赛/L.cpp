#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <array <int, 2> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0];
        v[i][1] = i;
    }
    
    for (int i = 31; i >= 0; i--) {
        int cnt = 0;
        for (int j = 0; j < v.size(); j++) {
            if (v[j][0] >> i & 1) {
                cnt++;
            }
        }
        if (cnt > 2) {
            vector <array <int, 2> > a;
            for (int j = 0; j < v.size(); j++) {
                if (v[j][0] >> i & 1) {
                    a.push_back({v[j][0], v[j][1]});
                }
            }
            v = a;
        }else if (cnt == 2) {
            for (int j = 0; j < v.size(); j++) {
                if (v[j][0] >> i & 1) {
                    cout << v[j][1] + 1 << ' ';
                }
            }
            return;
        }
    }

    cout << v[0][1] + 1 << ' ' << v[1][1] + 1 << '\n';
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