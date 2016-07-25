#include <stdio.h>

int main() {
	int T, i, j, k, d[11][11] = {};
	scanf("%d", &T);
	for (j = 0; j <= 10; ++j) d[1][j] = 1;
	for (i = 2; i <= 10; ++i) for (j = 0; j <= 10; ++j)
		for (k = j; k <= 10; k += i) d[i][k] += d[i - 1][j];
	while (T--) {
		scanf("%d%d", &j, &i);
		printf("%d\n", d[i][j]);
	}
	return 0;
}
