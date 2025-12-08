#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 10;
bool a[MAXN];

void solve ()
{
    string x;
    cin >> x;
    
    memset(a, false, sizeof(a));

    for (char c : x) {
        a[c - '0'] = true;
    }
    
    for (int i = 0; i < 10; i++) {
        if (a[i] == true) {
            cout << i << endl;
            return;
        }
    }

    return;
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _ = 1;
	cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}