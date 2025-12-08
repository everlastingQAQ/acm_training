#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1000 + 5;
bool is_prime [MAXN];
vector <int> prime;
int n;

void solve ()
{
    cin >> n;
    if (n <= 1) {
        cout << 0;
        return;
    }else if (n > 1 && n <= 5) {
        cout << n * 8;
        return;
    }else if (n > 5) {
        int sum = 40;
        for (int i = 9; i < n - 5 + 9; i++) {
            sum += i;
        }
        if (sum >= 300) {
            cout << 300;
            return;
        }else {
            cout << sum;
            return;
        }
    }
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