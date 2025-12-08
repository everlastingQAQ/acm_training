// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const int MAXN = 2e5 + 5;
// int a[MAXN];
// int vis[MAXN];

// void solve ()
// {
//     int n, k;
//     cin >> n >> k;

//     memset(vis, 0, sizeof(vis));
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         vis[a[i]]++; 
//     }

//     int cnt = 0;
//     for (int i = 0; i <= k; i++) {
//         //cout << vis[i] << endl;
//         if (vis[i] == 0 && i != k) {
//             cnt++;
//         }else if (i == k && vis[i] != 0) {
//             cnt += max(0, vis[i] - cnt);
//         }
//     }

//     cout << cnt << endl;
// }

// int main ()
// {
//     int t;
//     cin >> t;

//     while (t--) {
//         solve();
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
int a[MAXN];
int vis[MAXN];

void solve ()
{
    int n, k;
    cin >> n >> k;

    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        vis[a[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (vis[i] == 0) {
            ans++;
        }
    }

    ans = max(ans, vis[k]);

    cout << ans << endl;

}

int main ()
{
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

