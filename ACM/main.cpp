#include <bits/stdc++.h>
using namespace std;

#define R1 for (int i1 = 0, a; i1 < n && (a = A[i1], 1); ++i1)
#define R2 for (int i2 = i1 + 1, b; i2 < n && (b = A[i2], 1); ++i2)
#define R3 for (int i3 = i2 + 1, c; i3 < n && (c = A[i3], 1); ++i3)
#define R4 for (int i4 = i3 + 1, d; i4 < n && (d = A[i4], 1); ++i4)
#define R5 for (int i5 = i4 + 1, e; i5 < n && (e = A[i5], 1); ++i5)
#define R6 for (int i6 = i5 + 1, f; i6 < n && (f = A[i6], 1); ++i6)
#define R7 for (int i7 = i6 + 1, g; i7 < n && (g = A[i7], 1); ++i7)
#define R8 for (int i8 = i7 + 1, h; i8 < n && (h = A[i8], 1); ++i8)
#define R9 for (int i9 = i8 + 1, i; i9 < n && (i = A[i9], 1); ++i9)
#define R10 for (int i10 = i9 + 1, j; i10 < n && (j = A[i10], 1); ++i10)

// 转成整数运算更快
vector<int> A;
int n;
const int ans = 12345; // 123.45

inline float G(int x) { return x / 100.0; }

void f1() { R1 if (a == ans) printf("%.2f = %.2f\n", G(a), G(ans)); }
void f2() { R1 R2 if (a + b == ans) printf("%.2f + %.2f = %.2f\n", G(a), G(b), G(ans)); }
void f3() { R1 R2 R3 if (a + b + c== ans) printf("%.2f + %.2f + %.2f = %.2f\n", G(a), G(b), G(c), G(ans)); }
void f4() { R1 R2 R3 R4 if (a + b + c + d == ans) printf("%.2f + %.2f + %.2f + %.2f = %.2f\n", G(a), G(b), G(c), G(d), G(ans)); }
void f5() { R1 R2 R3 R4 R5 if (a + b + c + d + e == ans) printf("%.2f + %.2f + %.2f + %.2f + %.2f = %.2f\n", G(a), G(b), G(c), G(d), G(e), G(ans)); }
void f6() { R1 R2 R3 R4 R5 R6 if (a + b + c + d + e + f == ans) printf("%.2f + %.2f + %.2f + %.2f + %.2f + %.2f = %.2f\n", G(a), G(b), G(c), G(d), G(e), G(f), G(ans)); }
void f7() { R1 R2 R3 R4 R5 R6 R7 if (a + b + c + d + e + f + g == ans) printf("%.2f + %.2f + %.2f + %.2f + %.2f + %.2f + %.2f = %.2f\n", G(a), G(b), G(c), G(d), G(e), G(f), G(g), G(ans)); }
void f8() { R1 R2 R3 R4 R5 R6 R7 R8 if (a + b + c + d + e + f + g + h == ans) printf("%.2f + %.2f + %.2f + %.2f + %.2f + %.2f + %.2f + %.2f = %.2f\n", G(a), G(b), G(c), G(d), G(e), G(f), G(g), G(h), G(ans)); }
void f9() { R1 R2 R3 R4 R5 R6 R7 R8 R9 if (a + b + c + d + e + f + g + h +i == ans) printf("%.2f + %.2f + %.2f + %.2f + %.2f + %.2f + %.2f + %.2f + %.2f = %.2f\n", G(a), G(b), G(c), G(d), G(e), G(f), G(g), G(h), G(i), G(ans)); }
void f10() { R1 R2 R3 R4 R5 R6 R7 R8 R9 R10 if (a + b + c + d + e + f + g + h + i +j == ans) printf("%.2f + %.2f + %.2f + %.2f + %.2f + %.2f + %.2f + %.2f + %.2f + %.2f = %.2f\n", G(a), G(b), G(c), G(d), G(e), G(f), G(g), G(h), G(i), G(j), G(ans)); }

int main() {
	A.reserve(10000); // 确保a至少能容纳10000个元素

	float t;
	// 5 6 7.9 8.71 8.8 9.01 9.07 10 10 10 11.22 11.24 11.36 11.9 11.94 12.39 12.69 12.8 12.82 13.29 13.46 13.6 14.78 15.19 15.81 16.54 17.01 17.07 17.43 18.32 30.2 30.32 46.36
	while (cin >> t) { A.push_back(int(t * 100)); }
	sort(A.begin(), A.end());
	n = A.size();

	f1(); f2(); f3(); f4(); f5();
	//f6(); f7(); f8(); f9(); f10();

	return 0;
}

