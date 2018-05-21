#include <bits/stdc++.h>
using namespace std;
#define rep(i,b) for(int i=0; i<(b); ++i)
typedef long long LL;

const LL MOD = 1000000009;

LL PowMod(LL a, LL p, LL m = MOD) {
	if (p==0) return 1;
	LL ans = PowMod(a, p/2);
	ans = ans * ans % m;
	if (p%2 == 1) ans = ans * a % m;
	return ans;
}

int main() {
	LL n, a, b, k;
	cin >> n >> a >> b >> k;
	string s;
	cin >> s;

	LL sum = 0, t = PowMod(a, n+1) * PowMod(b, MOD-2) % MOD;
	const LL d = PowMod(a, MOD-2) * b % MOD;
	rep(i, n+1) {
		t = t * d % MOD;
		if (s[i%k] == '-') sum = (sum - t) % MOD;
		else sum = (sum + t) % MOD;
	}
	sum = (sum + MOD) % MOD;
	cout << sum << endl;

	return 0;
}

