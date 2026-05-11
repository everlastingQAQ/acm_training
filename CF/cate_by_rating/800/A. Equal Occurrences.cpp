#include <bits/stdc++.h>
using namespace std;
const int MAXN = 103;

bool cmp (int a, int b) {
    return a > b;
}

int main ()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int a[MAXN] = {};
        int cnt[MAXN] = {};
        for (int j = 0; j < n; j++) {
            cin >> a[j];
            cnt[a[j]]++;
        }
        int count = 0;
       
        sort(cnt, cnt + MAXN, cmp);
        int temp;
        for (int k = 0; k < MAXN; k++) {
            if (cnt[k] != 0) {
                count++;
            }
            if (cnt[k] == 0) {
                temp = cnt[k - 1];
                break;
            }
        }

        int maxium = temp * count;
        for (int k = 0; k < MAXN; k++) {
            int p = 0;
            for (int l = k + 1; l < count; l++) {
                if (cnt[l] == cnt[k]) {
                    l++;
                    p++;
                }else {
                    break;
                }
            }
            if (cnt[k] * (p + k + 1) > maxium) {
                maxium = cnt[k] * (p + k + 1);
            }
        }

        cout << maxium << endl;
    }

    return 0;
}