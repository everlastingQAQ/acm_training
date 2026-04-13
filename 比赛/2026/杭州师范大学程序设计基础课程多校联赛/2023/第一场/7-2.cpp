#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1000 + 5;
bool is_prime [MAXN];
vector <int> prime;
int n;

void solve ()
{
    string s;
    cin >> s;

    int cnt = 0;
    for (char i : s) {
        if ((i - '0') % 2 == 0) {
            cnt++;
        }
    }

    cout << cnt;
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	//cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}