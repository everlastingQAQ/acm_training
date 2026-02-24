#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack <char> stk;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            stk.pop();
        }else {
            stk.push('(');
            
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/


// ()()
// ()(()())
// (()(()))
// rbb
// rbbrbbrr
// rbbbrrbr