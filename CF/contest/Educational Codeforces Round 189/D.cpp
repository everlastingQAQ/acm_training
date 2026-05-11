#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 998244353;

void solve ()
{
    i64 n, x;
    cin >> n >> x;
    i64 cp0 = x / 4 + 1;
    i64 cp1 = x / 4;

    cp0 %= mod;
    cp1 %= mod;

    if (x % 4 == 2) {
        cp1++;
    }else if (x % 4 == 3) {
        cp1++;
    }
    cp0 %= mod;
    cp1 %= mod;

    i64 cs0 = (n - x) / 4;
    i64 cs1 = (n - x) / 4;
    cs0 %= mod;
    cs1 %= mod;
    if (n == x) {
        if (n % 4 == 1) cs1 = 1;
        else if (n % 4 == 3) cs0 = 1;
    }else if (x % 4 == 0 && n % 4 == 0) {

    }else if (x % 4 == 0 && n % 4 == 1) {
        cs1++;
    }else if (x % 4 == 0 && n % 4 == 2) {
        cs1++;
    }else if (x % 4 == 0 && n % 4 == 3) {
        cs1++;
        cs0++;
    }else if (x % 4 == 1 && n % 4 == 0) {
        cs1++;
        cs0++;
    }else if (x % 4 == 1 && n % 4 == 1) {
        cs1++;
    }else if (x % 4 == 1 && n % 4 == 2) {
        cs1++;
    }else if (x % 4 == 1 && n % 4 == 3) {
        cs1++;
        cs0++;
    }else if (x % 4 == 2 && n % 4 == 0) {
        cs0++;
    }else if (x % 4 == 2 && n % 4 == 1) {
        cs0++;
        cs1++;
    }else if (x % 4 == 2 && n % 4 == 2) {

    }else if (x % 4 == 2 && n % 4 == 3) {
        cs0++;
    }else if (x % 4 == 3 && n % 4 == 0) {
        cs0++;
    }else if (x % 4 == 3 && n % 4 == 1) {
        cs0++;
        cs1++;
    }else if (x % 4 == 3 && n % 4 == 2) {
        cs0++;
        cs1++;
    }else if (x % 4 == 3 && n % 4 == 3) {
        cs0++;
    }

    cs0 %= mod;
    cs1 %= mod;
    
    i64 a1 = cs0 * cp0 % mod;
    i64 a2 = cs1 * cp1 % mod;

    // cout << cs0 << ' ' << cs1 << ' ' << cp0 << ' ' << cp1 << '\n';
    i64 ans = (a1 + a2) % mod;
    cout << ans << '\n';
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}