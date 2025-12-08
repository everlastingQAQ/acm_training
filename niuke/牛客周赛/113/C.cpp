#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int a[MAXN];

int main ()
{
    int n;
    cin >> n;

    int cnt_2 = 0;
    int cnt_3 = 0;
    int cnt_5 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (a[i] % 2 == 0) {
            cnt_2++;
            a[i] /= 2;
        }
        while (a[i] % 3 == 0) {
            cnt_3++;
            a[i] /= 3;
        }
        while (a[i] % 5 == 0) {
            cnt_5++;
            a[i] /= 5;
        }
        
    }

    cout << min({cnt_2, cnt_3, cnt_5}); 

    return 0;
}