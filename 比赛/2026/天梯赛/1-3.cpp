#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int a, b;
    cin >> a >> b;
    int t = b - a;
    cout << t << '\n';
    if (t <= 0) {
        cout << "hai sheng ma?";
    }else if (t > 250) {
        cout << "jiu ting tu ran de...";
    }else {
        cout << "nin tai cong ming le!";
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