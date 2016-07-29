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
#define foreach(i,a) for(decltype((a).begin()) i=a.begin(); i!=(a).end(); ++i)

char s[100010];

//判断i~j之间是否为回文串
//是则返回-1，否则返回不匹配的下标i
int isHuiWen(int i, int j) {
	while (i < j) {
		if (s[i] != s[j]) return i;
		++i, --j;
	}
	return -1;
}

int fun() {
	int n = strlen(s) - 1;
	int d = isHuiWen(0, n);
	if (d == -1) return -1;
	else {
		int d1 = isHuiWen(d + 1, n - d);
		if (d1 == -1) return d;
		d1 = isHuiWen(d, n - d - 1);
		if (d1 == -1) return n - d;
		else return -1;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("res.txt", "w", stdout);
#endif
	while (scanf("%s", s) != EOF) {
		printf("%d\n", fun());
	}
	return 0;
}
