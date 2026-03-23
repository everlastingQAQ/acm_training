#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
	i64 k;
	cin >> n >> k;
	i64 s1 = 0, s2 = 0;
	for (int i = 1; i <= n; i++) {
		i64 t;
		cin >> t;
		if (s1 + t <= k) {
			s1 += t;
		}else {
			s2 += t;
		}
	}

	if (s1 > s2) {
		cout << "Takahashi";
	}else if (s1 == s2) {
		cout << "Draw";
	}else {
		cout << "Aoki";
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