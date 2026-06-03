#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int m, s;
    cin >> m >> s;
    if (s == 1) {
        cout << 1 << string(m - 1, '0') << ' ' << 1 << string(m - 1, '0');
        return;
    }else if (s == 0) {
        if (m == 1) {
            cout << 0 << ' ' << 0 << '\n';
        }else {
            cout << -1 << ' ' << -1 << '\n';
        }
        return;
    }else if (9 * m < s) {
        cout << -1 << ' ' << -1 << '\n';
        return;
    }
    
    string mn;
    int sum = s;
    sum -= 1;
    while (sum >= 9) {
        mn += '9';
        sum -= 9; 
    }
    if (sum) mn += (char)('0' + sum);
    if (mn.size() == m) {
        mn.pop_back();
        mn += (char)('0' + (sum + 1));
    }else if (mn.size() > m) {
        cout << -1 << ' ' << -1 << '\n';
        return;
    }else {
        int len = m - mn.size();
        string ss = string(len - 1, '0') + "1";
        mn += ss;
    }
    reverse(mn.begin(), mn.end());

    string mx;
    sum = s;
    while (sum >= 9) {
        mx += '9';
        sum -= 9;
    }
    if (sum) mx += (char)('0' + sum);
    if (mx.size() == m) {

    }else if (mx.size() > m) {
        cout << -1 << ' ' << -1 << '\n';
        return;
    }else {
        int len = m - mx.size();
        string ss = string(len, '0');
        mx += ss;
    }

    cout << mn << ' ' << mx << '\n';
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