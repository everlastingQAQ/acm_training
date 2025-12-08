#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 200010;

void solve ()
{
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;
    
    int l = 0, cnt = 0;

    while (l < n) {
        if (s1[l] != s2[l]) {
            cnt++;
            while (l < n && s1[l] != s2[l]) {
                l++;
            }
        }else {
            l++;
        }
    }
    
    cout << cnt << endl;
    
    return;
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _ = 1;
	//cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}