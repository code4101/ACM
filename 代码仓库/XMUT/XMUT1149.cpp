#include<stdio.h>
int main() {
	char c = getchar();
	printf("%s\n", (c >= 'a'&&c <= 'z') ? "Yes" : "No");
}
