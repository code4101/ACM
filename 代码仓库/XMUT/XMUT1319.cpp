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

int n, a, b, p[110];

int dist(int x) {
	if (x <= p[0]) return p[0] - x;
	if (x >= p[n - 1]) return x - p[n - 1];
	//否则肯定在两个点之间
	for (int i = 1; i <= n - 1; ++i) if (p[i] > x) {
		return min(x - p[i - 1], p[i] - x);
	}
}

int judge() {
	int x, d;
	int x0 = a, d0 = dist(a);
	for (int i = 0; i < n; ++i) {
		x = ((p[i] + p[i + 1]) >> 1);
		if (x < a) continue;
		if (x > b) break;
		d = dist(x);
		if (d > d0) d0 = d, x0 = x;
	}

	d = dist(b);
	if (d > d0) x0 = b;
	return x0;
}

int main() {
	//ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("res.txt", "w", stdout);
#endif
	while (cin >> n >> a >> b) {
		rep(i, n) read(p[i]);
		sort(p, p + n);
		cout << judge() << "\n";
	}

	return 0;
}
