#include <iostream>
#include <algorithm>
using namespace std;
//using ll = long long;
const int MAXN = 2e4 + 2;
int n;

bool cmp (int a1, int b1)
{
    return a1 > b1;
}

//错误代码
void solve ()
{
    cin >> n;
    int a[MAXN];
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];    
    }

    sort(a, a + n, cmp);

    long long ans = 0;

    for (int i = 0; i < n - 1; i++) {
        ans += sum;
        sum -= a[i];
    }

    cout << ans << endl;
}

int main ()
{
    //ios::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	//int _ = 1;
	//cin >> _;

    //while (_--) {
        solve();
    //}

    return 0;
}