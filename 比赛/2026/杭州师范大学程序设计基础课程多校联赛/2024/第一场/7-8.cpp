#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1000 + 5;
bool is_prime [MAXN];
vector <int> prime;
int n;

void Get_Prime () 
{
    memset(is_prime, true, sizeof(is_prime));

    is_prime[0] = false;
    is_prime[1] = false;
    
    for (int i = 2; i <= MAXN; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= MAXN; j++) {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

}

void solve ()
{
    cin >> n;

    Get_Prime ();
    
    int a[MAXN];
    memset(a, 0, sizeof(a));

    bool find_prime = false;
    int mn = 1001;
    for (int i = 0; i > n; i++) {
        cin >> a[i];
        mn = min(a[i], mn);
        if (is_prime[a[i]] == true) {
            find_prime = true;
        }
    }

    if (find_prime) {
        cout << "QAQ";
        return;
    }

    int ans = mn;
    bool found = false;
    while (!found) {
        found = true;
        for (int c : a) {
            if (c % ans == 0) {
                found = false;
                break;
            }
        }
        if (found) {
            break;
        }
        ans--;
    }

    cout << ans << endl;

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