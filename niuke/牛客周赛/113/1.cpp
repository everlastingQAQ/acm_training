#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200010;
int a[MAXN];
 
int main ()
{
    int n;
    cin >> n;
 
    int ans = 1;
    int k = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    do {
        int p = pow(30, k);
        ans = a[0] % p;
        for (int i = 1; i < n; i++) {
            a[i] %= p;
            ans *= a[i];
        }
        k++;
 
    }while (ans == 0);
 
    cout << k - 1;
 
    return 0;
}