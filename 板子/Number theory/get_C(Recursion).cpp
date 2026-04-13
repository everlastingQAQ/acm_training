#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 C[35][35];

void init ()
{
    for (int i = 0; i <= 34; i++) {
        C[i][0] = 1, C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}

void solve ()
{
    
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}   