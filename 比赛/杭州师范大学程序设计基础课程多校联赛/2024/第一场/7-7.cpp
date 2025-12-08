#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 45 + 5;

void solve ()
{
    int n;
    cin >> n;

    int a[MAXN];
    memset(a, 0, sizeof(a));
    a[1] = 1;
    a[2] = 1;
    
    for (int i = 3; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }

    if (a[n] % 3 == 0) {
        cout << 'Y';
    }else {
        cout << 'N'; 
    }
    
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