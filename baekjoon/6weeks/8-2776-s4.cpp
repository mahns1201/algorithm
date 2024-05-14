#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    날짜: 2024-05-15
	횟수: 1
*/

int t, tt, n, m;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	
	for(int i=0; i<t; i++) {
		v.clear();
		
		cin >> n;
		for (int j=0; j<n; j++) {
			cin >> tt; 
			v.push_back(tt);
		}

		sort(v.begin(), v.end());
		
		cin >> m;
		for (int j=0; j<m; j++) {
			cin >> tt; 
			bool ok = false;
			int left = 0, right = 1000004;
			while (left <= right) {
				int mid = (left + right) / 2;
				// cout << "[0] " << mid << '\n';
				if (v.size() <= mid) right = mid - 1;
				else if (v[mid] == tt) {
					// cout << mid << ' ' << tt << '\n';
					ok = true;
					break;
				}
				else if (v[mid] < tt) left = mid + 1;
				else right = mid - 1;
			}

			if (ok) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}

	return 0;
}