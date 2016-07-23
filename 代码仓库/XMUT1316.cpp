#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 任意整数的读入外挂 
template <typename T> inline int read(T& x) {
	int c, sign = 1; x = 0;
	while (!(((c = getchar()) >= '0'&&c <= '9') || c == '-')) if (c == EOF) return c;
	if (c == '-') sign = -1; else x = x * 10 + c - '0';
	while (((c = getchar()) >= '0'&&c <= '9')) x = x * 10 + c - '0';
	x *= sign;
	return 1;
}

struct Point{
	int x, y;
	Point(int a = 0, int b = 0) :x(a), y(b) { }
};

char map[25][25];

#define TEST(x,y) if (map[x][y]) {que.push(Point(x, y)); map[x][y]=0;}
int getArea(int x, int y) {
	queue<Point> que; que.push(Point(x, y));
	map[x][y] = 0;

	int area = 0;
	Point p;
	while (!que.empty()) {
		++area;
		p = que.front(); que.pop();
		x = p.x, y = p.y;
		TEST(x - 1, y); TEST(x, y - 1); TEST(x, y + 1); TEST(x + 1, y);
		TEST(x - 1, y - 1); TEST(x - 1, y + 1); TEST(x + 1, y - 1); TEST(x + 1, y + 1);
	}
	return area;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int T; cin >> T;

	int i, j, n, m, s;
	while (T--) {
		cin >> n >> m;	//我这里记为n行m列
		memset(map, 0, 25 * 25);
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= m; ++j)
				read(map[i][j]);
		s = 0;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				if (map[i][j]) s = max(s, getArea(i, j));
			}
		}
		cout << s << "\n";
	}

	return 0;
}
