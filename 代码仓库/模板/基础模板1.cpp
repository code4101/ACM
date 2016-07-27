#include "基础模板.cpp"

// 任意整数的读入外挂 
template <typename T> inline int read(T& x) {
	int c, sign = 1; x = 0;
	while (!(((c = getchar()) >= '0'&&c <= '9') || c == '-')) if (c == EOF) return c;
	if (c == '-') sign = -1; else x = x * 10 + c - '0';
	while (((c = getchar()) >= '0'&&c <= '9')) x = x * 10 + c - '0';
	x *= sign;
	return 1;
}

const double eps = 1e-10, pi = acos(-1.0);

struct Point2i {
	int x, y;
	Point2i(int a = 0, int b = 0) :x(a), y(b) { }

	bool operator < (const Point2i& b) const {
		if (x == b.x) return y < b.y;
		else return x < b.x;
	}
};

struct Point2f {
	float x, y;
	Point2f(float a = 0.0, float b = 0.0) :x(a), y(b) { }

	bool operator < (const Point2f& b) const {
		if (x == b.x) return y < b.y;
		else return x < b.x;
	}
};

//从大到小排序：sort(a.begin(),a.end(),greater<int>())
