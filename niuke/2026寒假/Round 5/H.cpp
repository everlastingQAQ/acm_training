#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > v(n + 1, vector <int> (n + 1));
    int s = 0;
    int s1 = 0, c1 = 0;
    int s2 = 0, c2 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
            if ((i & 1) == (j & 1)) {
                s1 += v[i][j];
                c1++;
            }else {
                s2 += v[i][j];
                c2++;
            }
            s += v[i][j];
        }
    }
    
    if (s % (n * n)) {
        cout << "No\n";
        return;
    }
    
    int t = s / n / n;

    if (c1 && s1 % c1 || c2 && s2 % c2) {
        cout << "No\n";
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += v[i][j];
        }
        if ((sum & 1) != ((n * t) & 1)) {
            cout << "No\n";
            return;
        } 
    }

    for (int j = 1; j <= n; j++) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += v[i][j];
        }
        if ((sum & 1) != ((n * t) & 1)) {
            cout << "No\n";
            return;
        } 
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