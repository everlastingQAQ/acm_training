#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n;
    cin >> n;
    if (n & 1) {
        for (int i = 1; i <= (n - 1) / 2; i++) {
            if (i & 1) cout << "aa";
            else cout << "bb";
        }
        cout << "e";
        cout << '\n';
        for (int i = 1; i <= (n - 1) / 2; i++) {
            if (i & 1) cout << "bb";
            else cout << "aa";
        }
        cout << "e";
        cout << '\n';
        cout << "f";
        for (int i = 1; i <= (n - 1) / 2; i++) {
            if (i & 1) cout << "cc";
            else cout << "dd";
        }
        cout << '\n';
        cout << "f";
        for (int i = 1; i <= (n - 1) / 2; i++) {
            if (i & 1) cout << "dd";
            else cout << "cc";
        }
        cout << '\n';
    }else {
        for (int i = 1; i <= n / 2; i++) {
            if (i & 1) cout << "aa";
            else cout << "bb";
        }
        cout << '\n';
        for (int i = 1; i <= n / 2; i++) {
            if (i & 1) cout << "bb";
            else cout << "aa";
        }
        cout << '\n';
        cout << "e";
        for (int i = 1; i <= (n - 2) / 2; i++) {
            if (i & 1) cout << "cc";
            else cout << "dd";
        }
        cout << "f";
        cout << '\n';
        cout << "e";
        for (int i = 1; i <= (n - 2) / 2; i++) {
            if (i & 1) cout << "dd";
            else cout << "cc";
        }
        cout << "f";
        cout << '\n';
    }
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

aabb
bbaa
eccf
eddf

aabbe
bbaae
fccdd
fddcc

aabbaa
bbaabb
eccddf
eddccf

*/