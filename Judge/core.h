#pragma once
#include <atlstr.h>
#include <atltypes.h>
#include <direct.h>
#include <io.h>
#include <omp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <cassert>
#include <cmath>
#include <ctime>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <strstream>
#include <unordered_set>
#include <vector>
#include <xstring>
using namespace std;

#define rep(i,b) for(int i=0; i<(b); ++i)
#define FOR(i, a, b) for(int i=(a); i<(b); ++i)

#define COUT(v) cout << #v << ": " << v << "\n";

string Format(const string fmt_str, ...);

class CTime {
public:
	// _sum:初始耗时
	CTime(clock_t _sum = 0);
	
	//重置计时器为0
	void tic();
	//输出统计用时：msg若为空，则不在dos输出提示内容
	clock_t toc(string msg = "");

	//暂停计时
	void turnOff();
	//恢复计时
	void turnOn();

private:
	//存储时使用的单位是毫秒
	clock_t sum;
	clock_t start;
};

// 将一个文件以string的方式读入
string ReadFile(const char* FileName);


// 从"data"文件获得数据
//   读取成功返回true，返回false表示不存在这个数据
bool GetTestData(string PID, int testId, string &in, string &out);

typedef pair<string,string> pss;

class JudgeData {
public:
	//data[i][j]: 第i题的第j组数据, first是输入，second是输出
	vector<vector<pss>> vvdata;

	JudgeData() {}

	// 通过一个文件来够来
	JudgeData(string fileName);

	void Read(string fileName);

	//按照格式将数据存储到文件
	void Save(string fileName);

private:
	vector<pss> AddOneProblem(string content);
};

string RemoveTailBlank(string in);

