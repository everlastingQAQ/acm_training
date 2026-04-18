#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <array <int, 2> > v(n + 1);
    vector <int> a;
    vector <int> b;
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0];
        v[i][1] = i;
        if (v[i][0] > 1) a.push_back(i);
        else b.push_back(i);
    }

    vector <array <int, 2> > ans;
    for (int i = 1; i <= n; i++) {
        
    }
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