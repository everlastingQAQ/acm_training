#include <bits/stdc++.h>
using namespace std;

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int length = s.size();

    int cnt_0 = 0;
    for (int i = 0; i < length; i++) {
        if (s[i] == '0') cnt_0++;
    }

    int ans = 0;
    for (int i = 0; i < cnt_0; i++) {
        if (s[i] == '1') ans++;
    }

    cout << ans << endl;

}

int main ()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}