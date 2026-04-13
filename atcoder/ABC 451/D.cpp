#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector <i64> v;

void init ()
{
	v.reserve(1e6);
	vector <i64> a;
	i64 cur = 1;
	a.push_back(cur);
	for (int i = 1; i <= 26; i++) {
		cur *= 2;
		a.push_back(cur);
	}
	
	auto cal = [&] (int cnt, vector <int> b) -> void {

	};

	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = j; k <= )
		}
	}
}

void solve ()
{
    
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
} 
