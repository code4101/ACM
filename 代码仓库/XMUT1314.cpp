#include <cstdio>
#include <iostream>
using namespace std;
#define rep(i,b) for(int i=0; i<(b); ++i)
typedef long long LL;

// 任意整数的读入外挂 
template <typename T> inline int read(T& x) {
	int c, sign = 1; x = 0;
	while (!(((c = getchar()) >= '0'&&c <= '9') || c == '-')) if (c == EOF) return c;
	if (c == '-') sign = -1; else x = x * 10 + c - '0';
	while (((c = getchar()) >= '0'&&c <= '9')) x = x * 10 + c - '0';
	x *= sign;
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int T; cin >> T;

	int n, k, s, t;
	LL ans;
	while (T--) {
		read(n); read(k);
		s = 0;
		ans = LL(n)*(n + 1) / 2;
		rep(i, n) {
			read(t);
			if (t <= k) ans -= ++s;
			else s = 0;
		}
		cout << ans << "\n";
	}

	return 0;

}
