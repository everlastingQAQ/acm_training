#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n, k;
    string s;
    cin >> n >> k >> s;
    vector <int> v(n);
    int c0 = 0, c1 = 0;
    for (int i = n - 1; i > 0; i--) {
        if (s[i] == '0') c0++;
        else c1++;
        v[i] = c1 - c0;
    }
    sort(v.begin() + 1, v.end());
    int sum = 0;
    int ans = 1;
    for (int i = n - 1; i > 0; i--) {
        if (v[i] < 0) {
            cout << "-1\n";
            return;
        }
        sum += v[i];
        ans++;
        if (sum >= k) {
            break;
        }
    }
    cout << (sum >= k ? ans : -1) << '\n'; 
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