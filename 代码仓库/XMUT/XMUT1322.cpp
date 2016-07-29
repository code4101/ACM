//注意：比赛的时候，该题后台数据错放到1323题。

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

bool getStr(char *s) {
	int i = 0;
	while (1) {
		s[i] = tolower(getchar());
		if (s[i] == -1) return false;
		if (s[i] == ' ' || s[i] == '\n') continue;
		if (s[i] == '.' || s[i] == '?' || s[i] == '!') break;
		++i;
	}
	s[i + 1] = 0;
	return true;
}

const char P[] = "acdream";
int f[10];

void getFail(const char* P, int* f) {
	int m = strlen(P);
	f[0] = f[1] = 0;
	for (int i = 1; i < m; ++i) {
		int j = f[i];
		while (j && P[i] != P[j]) j = f[j];
		f[i + 1] = P[i] == P[j] ? j + 1 : 0;
	}
}

int kmpCnt(const char *T) {
	int res = 0;
	int n = strlen(T), m = strlen(P);
	int j = 0;
	rep(i, n) {
		while (j && P[j] != T[i]) j = f[j];
		if (P[j] == T[i]) ++j;
		if (j == m) ++res;
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("res.txt", "w", stdout);
#endif
	getFail(P, f);
	while (getStr(s)) {
		//cout << s << "\n";
		printf("%d\n", kmpCnt(s));
	}
	return 0;
}
