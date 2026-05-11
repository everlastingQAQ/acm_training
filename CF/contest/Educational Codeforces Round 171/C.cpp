#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    deque <i64> dq;
    i64 ans = 0;
    for (int i = n; i >= 1; i--) {
        int t = s[i] - '0';
        if (t == 1) {
            dq.push_back(i);
        }else {
            if (!dq.empty()) dq.pop_front();
            ans += i;
        }
    }
    while (!dq.empty()) {
        ans += dq.back();
        dq.pop_back();
        if (dq.empty()) break;
        dq.pop_front();
    }
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