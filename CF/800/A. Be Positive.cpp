#include <bits/stdc++.h>
using namespace std;
const int MAXN = 11;

int main ()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int cnt_0 = 0;
        int cnt_negative1 = 0;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (a == -1) {
                cnt_negative1++;
            }else if (a == 0) {
                cnt_0++;
            }
        }
        cout << cnt_0 + (cnt_negative1 % 2) * 2 << endl;
    }

    return 0;
}