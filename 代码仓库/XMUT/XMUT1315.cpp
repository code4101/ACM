#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int fun(int n, int m, int k) {
	if (k == 1) return 1;
	int ans = 0;
	for (int i = m; i <= n / k; ++i) {
		ans += fun(n - i, i, k - 1);
	}
	return ans;
}

int main() {
	int T; cin >> T;

	int n, k;
	while (T--) {
		cin >> n >> k;
		cout << fun(n, 0, k) << "\n";
	}

	return 0;

}
