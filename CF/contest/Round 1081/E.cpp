#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> a(n + 1), b(n + 1);
    map <int, int> mpa, mpb;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mpa[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        mpb[b[i]]++;
    }

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