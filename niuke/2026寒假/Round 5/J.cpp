#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n = 3;
    map <int, int> mp;
    vector <vector <int> > v(n + 1, vector <int> (n + 1));
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
            mp[v[i][j]]++;
            if (i == 1) sum += v[i][j];
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (mp[i] != 1) {
            cout << "No\n";
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        int s = 0;
        for (int j = 1; j <= n; j++) {
            s += v[i][j];
        }
        if (sum != s) {
            cout << "No\n";
            return;
        }
    }

    for (int j = 1; j <= n; j++) {
        int s = 0;
        for (int i = 1; i <= n; i++) {
            s += v[i][j];
        }
        if (s != sum) {
            cout << "No\n";
            return;
        }
    }

    if (v[1][1] + v[2][2] + v[3][3] != sum) {
        cout << "No\n";
        return;
    }
    if (v[1][3] + v[2][2] + v[3][1] != sum) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}   
    
int32_t main ()
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/