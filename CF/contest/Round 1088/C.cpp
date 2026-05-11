#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n, k;
  	cin >> n >> k;
  	vector <int> a(n + 1), b(n + 1);
  	for (int i = 1; i <= n; i++) {
  		cin >> a[i];
  	}  
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	map <int, int> mp1, mp2;
	deque <int> pos;
	for (int i = 1; i <= k; i++) {
		if (b[i] == -1) {
			pos.push_back(i);
			continue;
		}
		mp2[b[i]]++;
		if (mp2[b[i]] > 1) {
			cout << "NO\n";
			return;
		}
	}

	set <int> st;
	for (int i = 1; i <= k; i++) {
		if (!mp2[a[i]]) {
			if (pos.empty()) {
				cout << "NO\n";
				return;
			}
			int p = pos.front();
			pos.pop_front();
			b[p] = a[i];
			mp2[b[p]]++;
		}
		mp1[a[i]] = 1;
	}

	for (int i = k + 1; i <= n; i++) {
		if (b[i] == -1) b[i] = a[i];
		mp1[a[i - k]]--;
		mp2[b[i - k]]--;
		if (mp1[a[i - k]] != mp2[a[i - k]]) {
			st.insert(a[i - k]);
		}
		if (mp1[b[i - k]] != mp2[b[i - k]]) {
			st.insert(b[i - k]);
		}

		mp1[a[i]]++;
		mp2[b[i]]++;

		if (mp2[b[i]] > 1) {
			cout << "NO\n";
			return;
		}

		if (mp1[a[i]] != mp2[a[i]]) {
            st.insert(a[i]);
        }else {
            st.erase(a[i]);
        }

		if (mp1[b[i]] != mp2[b[i]]) {
            st.insert(b[i]);
        }else {
            st.erase(b[i]);
        }

		if (!st.empty()) {
            cout << "NO\n";
            return;
        }
	}

	cout << "YES\n";
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 