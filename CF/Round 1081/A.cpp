#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    i64 ans = 0;
    vector <char> t(2 * n);
    for (int i = 0; i < n; i++) {
        t[i] = s[i];
        t[n + i] = s[i];
    }
    
    for (int i = 0; i < n; i++) {
        i64 cur = 1;
        for (int j = i; j < i + n; j++) {
            if (j < i + n - 1 && t[j + 1] != t[j]) cur++;
        }
        ans = max(ans, cur);
    }

    cout << ans << '\n';

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

/*
  /\_/\
 (= ._.)
 / >  \>
*/