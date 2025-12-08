#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1000 + 5;
bool is_prime [MAXN];
vector <int> prime;
int n;

void solve ()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c < 1000 && a % 12 == 0 && a - b > b - c) {
        cout << "Yes";
    }else {
        cout << "No";
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