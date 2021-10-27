#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int sum = 0;
		vector<int> indices(n);
		// calculate the sum and store the index (1-based) in a vector
		for (int i = 0; i < n; i++) {
			sum += a[i];
			indices[i] = i + 1;
		}
		auto Prime = [](int x) {
			if (x <= 1) {
				return false;
			}
			bool prime = true;
			for (int i = 2; i <= (int) sqrt(x); i++) {
				if (x % i == 0) {
					prime = false;
					break;
				}
			}
			return prime;
		};
		if (!Prime(sum)) {
			// if the sum already composite, then there is nothing to do but to output it
			cout << n << '\n';
			for (int index : indices) {
				cout << index << " ";
			}
		} else {
			// otherwise, we need to find one number that we need to remove to make the sum composite
			for (int i = 0; i < n; i++) {
				if (!Prime(sum - a[i])) {
					auto it = find(indices.begin(), indices.end(), i + 1);
					indices.erase(it);
					break;
				}
			}
			cout << indices.size() << '\n';
			for (int index : indices) {
				cout << index << " ";
			}
		}
		cout << '\n';
	}
	return 0;
}
