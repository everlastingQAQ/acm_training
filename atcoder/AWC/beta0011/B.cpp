#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int h, w, k;
    cin >> h >> w >> k;
    char c1, c2;
    cin >> c1 >> c2;
    vector <vector <char> > v(h + 1, vector <char> (w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> v[i][j];
        }
    } 

    vector <vector <char> > a(h * k + 10, vector <char> (w * k + 10));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int t = (i - 1) * k + 1;
            int tt = (j - 1) * k + 1;
            if (v[i][j] == '#') {
                for (int p = t; p < t + k; p++) {
                    for (int q = tt; q < tt + k; q++) {
                        a[p][q] = c1;
                    }
                }
            }else {
                for (int p = t; p < t + k; p++) {
                    for (int q = tt; q < tt + k; q++) {
                        a[p][q] = c2;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= h * k; i++) {
        for (int j = 1; j <= w * k; j++) {
            cout << a[i][j];
        }
        cout << '\n';
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