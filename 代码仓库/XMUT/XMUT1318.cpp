#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
#define rep(i,b) for(int i=0; i<(b); ++i)
#define foreach(i,a) for(__typeof((a).begin()) i=a.begin(); i!=(a).end(); ++i)

// 任意整数的读入外挂 
template <typename T> inline int read(T& x) {
	int c, sign = 1; x = 0;
	while (!(((c = getchar()) >= '0'&&c <= '9') || c == '-')) if (c == EOF) return c;
	if (c == '-') sign = -1; else x = x * 10 + c - '0';
	while (((c = getchar()) >= '0'&&c <= '9')) x = x * 10 + c - '0';
	x *= sign;
	return 1;
}

int n, k, a[1010], d[1010];

bool judge() {
	sort(a, a + n);
	sort(d, d + n);
	rep(i, n) if (a[i] + d[n - i - 1] < k) return false;
	return true;
}

int main() {
	//ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("res.txt", "w", stdout);
#endif
	while (cin >> n >> k) {
		rep(i, n) read(a[i]);
		rep(i, n) read(d[i]);
		cout << (judge() ? "YES" : "NO") << "\n";
	}

	return 0;
}
