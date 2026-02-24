#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s;
    cin >> s;
    int cur = 0;
    vector <int> v;
    for (char c : s) {
        if (c == '0') {
            if (cur == 0) {
                cur = 3;
                cout << 3;
            }else if (cur == 1) {
                cur = 2;
                cout << 2;
            }else if (cur == 2) {
                cur = 1;
                cout << 1;
            }else if (cur == 3) {
                cur = 0;
                cout << 0;
            }
        }else if (c == '1') {
            if (cur == 0) {
                cur = 0;
                cout << 0;
            }else if (cur == 1) {
                cur = 3;
                cout << 3;
            }else if (cur == 2) {
                cur = 2;
                cout << 2;
            }else if (cur == 3) {
                cur = 1;
                cout << 1;
            }
        }else if (c == '2') {
            if (cur == 0) {
                cur = 1;
                cout << 1;
            }else if (cur == 1) {
                cur = 0;
                cout << 0;
            }else if (cur == 2) {
                cur = 3;
                cout << 3;
            }else if (cur == 3) {
                cur = 2;
                cout << 2;
            }
        }else if (c == '3') {
            if (cur == 0) {
                cur = 2;
                cout << 2;
            }else if (cur == 1) {
                cur = 1;
                cout << 1;
            }else if (cur == 2) {
                cur = 0;
                cout << 0;
            }else if (cur == 3) {
                cur = 3;
                cout << 3;
            }
        }else if (c == '4') {
            if (cur == 0) {
                cur = 1;
                cout << 1;
            }else if (cur == 1) {
                cur = 2;
                cout << 2;
            }else if (cur == 2) {
                cout << 3;
                cur = 3;
            }else if (cur == 3) {
                cout << 0;
                cur = 0;
            }
        }else if (c == '5') {
            if (cur == 0) {
                cur = 3;
                cout << 3;
            }else if (cur == 1) {
                cur = 0;
                cout << 0;
            }else if (cur == 2) {
                cout << 1;
                cur = 1;
            }else if (cur == 3) {
                cout << 2;
                cur = 2;
            }
        }
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
  /\_/\
 (= ._.)
 / >  \>
*/