#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n;
    cin >> n;
    set <int> st;
    for (int i = 0; i <= 9; i++) {
        int t = i;
        for (int j = 0; j <= 9; j++) {
            t += j * 10;
            for (int k = 0; k <= 9; k++) {
                t += k * 100;
                for (int l = 0; l <= 9; l++) {
                    t += l * 1000;
                    for (int m = 1; m <= 3; m++) {
                        t += m * 10000;
                        if (t <= 30000) {
                            int a = t / 100;
                            int b = (t - m * 10000) / 10;
                            int c = (t - m * 10000 - l * 1000);
                            if (a % n == 0 && b % n == 0 && c % n == 0) {
                                st.insert(t);
                            } 
                        }
                        t -= m * 10000;
                    }
                    t -= l * 1000;
                }
                t -= k * 100;   
            }
            t -= j * 10;
        }
        t -= i;
    }
    if (st.empty()) {
        cout << "No\n";
    }else {
        for (auto x : st) {
            cout << x << '\n';
        }
    }
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 