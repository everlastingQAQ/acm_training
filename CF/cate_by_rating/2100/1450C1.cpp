#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    int sum = 0;
    vector <vector <char> > v(n + 1, vector <char> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'X') sum++;
        }
    }
    
    for (int k = 0; k < 3; k++) {
        vector <vector <char> > a = v;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ((i + j) % 3 == k && a[i][j] == 'X') {
                    a[i][j] = 'O';
                    cnt++;
                }
            }
        }
        if (cnt * 3 <= sum) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cout << a[i][j];
                }
                cout << '\n';
            }
            return;
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