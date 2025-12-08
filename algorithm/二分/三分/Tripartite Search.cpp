
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;

int n, x;
int a[MAXN];

//解决单谷单峰问题

int main ()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int left = 1;
    int right = n;

    while (left <= right) {
        int mask1 = left + (right - left) / 3;
        int mask2 = right - (right - left) / 3;
        if (a[mask1] >= a[mask2]) {
            right = mask2 - 1;
        }else {
            left = mask1 + 1;
        }
    }
    cout << left; //哪个不取等就输出哪个
    return 0;
}