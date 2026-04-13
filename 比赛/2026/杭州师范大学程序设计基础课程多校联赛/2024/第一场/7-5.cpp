#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1;

bool is_true (int x)
{
    string s = to_string(x);

    int l = 0; 
    int r = s.size() - 1;

    bool p = true;
    while (l <= r) {
        if (s[l] == s[r]) {
            l++;
            r--;
            continue;
        }else {
            p = false;
            break;
        }
    }

    return p;
}

void solve ()
{
    int a, b;
    cin >> a >> b;

    int cnt = 0;
    for (int i = a; i <= b; i++) {
        if (is_true(i)) {
            cnt++;
        }else continue;
    }

    cout << cnt << endl;
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