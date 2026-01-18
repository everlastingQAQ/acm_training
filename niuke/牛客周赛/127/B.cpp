#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    vector <vector <int> > v(5, vector <int> (5));
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= 4; i++) {
        map <int, int> mp;
        for (int j = 1; j <= 4; j++) {
            mp[v[i][j]]++;
        }
        for (int k = 1; k <= 4; k++) {
            if (mp[k] != 1) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    for (int j = 1; j <= 4; j++) {
        map <int, int> mp;
        for (int i = 1; i <= 4; i++) {
            mp[v[i][j]]++;
        }
        for (int k = 1; k <= 4; k++) {
            if (mp[k] != 1) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    map <int, int> mp1;
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            mp1[v[i][j]]++;
        }
    }
    for (int k = 1; k <= 4; k++) {
        if (mp1[k] != 1) {
            cout << "NO" << '\n';
            return;
        }
    }
    
    map <int, int> mp2;
    for (int i = 3; i <= 4; i++) {
        for (int j = 1; j <= 2; j++) {
            mp2[v[i][j]]++;
        }
    }
    for (int k = 1; k <= 4; k++) {
        if (mp2[k] != 1) {
            cout << "NO" << '\n';
            return;
        }
    }

    map <int, int> mp3;
    for (int i = 1; i <= 2; i++) {
        for (int j = 3; j <= 4; j++) {
            mp3[v[i][j]]++;
        }
    }
    for (int k = 1; k <= 4; k++) {
        if (mp3[k] != 1) {
            cout << "NO" << '\n';
            return;
        }
    }

    map <int, int> mp4;
    for (int i = 3; i <= 4; i++) {
        for (int j = 3; j <= 4; j++) {
            mp4[v[i][j]]++;
        }
    }
    for (int k = 1; k <= 4; k++) {
        if (mp4[k] != 1) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}   
    
signed main ()
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