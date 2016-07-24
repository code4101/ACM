//改编自刘汝佳，原来的格式处理不对
#include<cstdio>
#include<stack>
using namespace std;
const int MAXN = 1000 + 10;

int n, target[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	while (scanf("%d", &n) == 1) {
		if (!n) break;
		while (1) {
			scanf("%d", &target[1]);
			if (!target[1]) {
				putchar('\n');
				break;
			}
			stack<int> s;
			int A = 1, B = 1;
			for (int i = 2; i <= n; i++)
				scanf("%d", &target[i]);
			int ok = 1;
			while (B <= n) {
				if (A == target[B]){ A++; B++; } //A直接到B
				else if (!s.empty() && s.top() == target[B]){ s.pop(); B++; }	//C顶端的到B
				else if (A <= n) s.push(A++);	//A还有元素，则进入C
				else { ok = 0; break; }			//否则失败
			}
			printf("%s\n", ok ? "Yes" : "No");
		}

	}
	return 0;
}
