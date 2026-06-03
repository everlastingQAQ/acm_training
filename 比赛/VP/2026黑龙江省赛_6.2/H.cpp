#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s; cin >> s;
    int pos = s.find('.');
    string t1 = s.substr (0, pos);
    string t2 = s.substr (pos + 1);

    int n1 = stoll (t1) * 4 - 3;
    int x = stoll(t2);
    x *= 4;
    int n2 = x / 100;

    int ans = n1 + n2;
    int a = x % 100;

    printf("%lld.", ans);
    printf("%02lld\n", a);
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