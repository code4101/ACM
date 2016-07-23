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
#include <random>
using namespace std; 

default_random_engine gen(time(NULL));
uniform_real_distribution<double> dis(0.0, 1.0);
auto dice = bind(dis, gen);

//实现randint(l,u)，返回[l,u]范围内的一个随机整数
int randint(int l, int u) {
	return (l + (u - l)*dice() + 0.5);
}

int main0() {
	freopen("out.txt", "w", stdout);
	for (int i = 0; i < 10000; i++) {
		cout << randint(0, 1) << " ";
	}
	return 0;
}
