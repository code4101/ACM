#include "基础模板.cpp"

// 读入一行字符串：过滤空行，返回字符串长度
int my_gets(char* s) {
	int k;
	while ((k = getchar()) == '\n');  // 空行重读
	if (k == -1) k = 0; else gets(s + 1);
	s[0] = k; return strlen(s);
}

//读取一个非空字符
//其实也不算读取可见字符，只能说滤除空格、回车
char getVisibleChar() {
	char ch;
	while (ch = getchar(), ch == ' ' || ch == '\n');
	return ch;
}
