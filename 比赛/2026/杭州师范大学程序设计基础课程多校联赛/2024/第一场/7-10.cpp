#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1000 + 5;

void solve ()
{
    int n, m, x;
    cin >> n >> m >> x;

    int cnt = 0;

    int a = x, b = 0;

    bool case1 = true;
    bool case2 = false;
    bool case3 = false;
    bool case4 = false;
    
    bool case5 = false;
    bool case6 = false;
    while (!case5 || !case6) {
        while (case1) {
            a++;
            b++;
            if (a == n && b == m) {
                case1 = false;
                case5 = true;
                break;
            }
            if (a == n && b != m) {
                cnt++;
                case2 = true;
                case1 = false;
                break;
            }else if (b == m && a != n) {
                cnt++;
                case4 = true;
                case1 = false;
                break;
            }
        }
        while (case2) {
            a--;
            b++;
            if (a == x && b == 0) {
                case2 = false;
                case5 = true;
                break;
            }
            if (b == m && a == 0) {
                case2 = false;
                case5 = true;
                break;
            }
            if (a == 0 && b != m) {
                cnt++;
                case1 = true;
                case2 = false;
                break;
            }else if (b == m && a != 0) {
                cnt++;
                case3 = true;
                case2 = false;
                break;
            }
        }
        while (case3) {
            a--;
            b--;
            if (b == 0 && a == 0) {
                case3 = false;
                case6 = true;
                break;
            }
            if (a == 0 && b != 0) {
                cnt++;
                case4 = true;
                case3 = false;
                break;
            }else if (b == 0 && a != 0) {
                cnt++;
                case2 = true;
                case3 = false;
                break;
            }
        }
        while (case4) {
            a++;
            b--;
            if (a == x && b == 0) {
                case5 = true;
                case4 = false;
                break;
            }
            if (b == 0 && a == n) {
                case4 = false;
                case5 = true;
                break;
            }
            if (a == n && b != 0) {
                cnt++;
                case3 = true;
                case4 = false;
                break;
            }else if (b == 0 && a != n) {
                cnt++;
                case1 = true;
                case4 = false;
                break;
            }
        }
        if (case5 == true || case6 == true) {
            break;
        }
    }

    if (case5) {
        cout << "Xunwuqishi is a vegetable dog.";
    }else {
        cout << cnt;
    }

    return;
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