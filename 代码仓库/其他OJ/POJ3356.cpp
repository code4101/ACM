//编辑距离
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m, t, d[1010];
char a[1010], b[1010];

int editDis() {
	if (!n || !m) return n + m;
	for (int j = 0; j <= m; ++j) d[j] = j;

	for (int i = 1; i <= n; ++i) {
		t = i - 1; d[0] = i;
		for (int j = 1; j <= m; ++j) {
			int d1 = t + (a[i - 1] == b[j - 1] ? 0 : 1);
			int d2 = __min(d[j - 1], d[j]) + 1;
			t = d[j]; d[j] = __min(d1, d2);
		}
	}

	t = d[m]; return t;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("res.txt", "w", stdout);
#endif
	while (scanf("%d%s%d%s", &n, a, &m, b) != EOF)
		printf("%d\n", editDis());
	return 0;
}
