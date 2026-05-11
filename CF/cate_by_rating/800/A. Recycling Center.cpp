#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 32;
vector <ll> a;

bool cmp (int c, int d) {
    return c > d;
}

int FIND (int n, int c)
{
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= c) {
            ans = i;
            return ans;
        }
    }

    return -1;
}

void solve ()
{
    int n, c;
    cin >> n >> c;

    int N = n;

    a.clear();
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.begin() + n, cmp);

    int count = 0;
    while (c > 0) {
        int digit = FIND(n, c);
        if (digit == -1) {
            break;
        }else {
            //cout << a[digit] << endl;
            a.erase(a.begin() + digit);
            n--;
            for (int i = 0; i < n; i++) {
                a[i] *= 2;
            }
            count++;
        }
    }

    cout << N - count << endl;
}

int main ()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}