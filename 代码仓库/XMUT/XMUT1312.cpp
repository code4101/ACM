#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char s[6][10], ss[10];
const int len[6] = { 0, 3, 2, 4, 3, 5 };

bool judge(int n, int id) {
	sprintf(ss, "%d", n);
	if (len[id] != strlen(ss)) return false;
	for (int i = 0; ss[i]; ++i) {
		if ((s[id][i] != '*') && (s[id][i] != ss[i])) return false;
	}
	return true;
}

int main() {
	int T; cin >> T;

	int a, b, c, d, e, ans;
	while (T--) {
		cin >> s[1] >> s[2] >> s[3] >> s[4] >> s[5];
		ans = 0;
		for (a = 100; a <= 999; ++a) {
			if (!judge(a, 1)) continue;
			for (b = 10; b <= 99; ++b) {
				if (!judge(b, 2)) continue;
				c = a * (b % 10), d = a * (b / 10), e = a * b;
				if (judge(c, 3) && judge(d, 4) && judge(e, 5)) ++ans;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
