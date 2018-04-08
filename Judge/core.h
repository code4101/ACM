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
	// _sum:��ʼ��ʱ
	CTime(clock_t _sum = 0);
	
	//���ü�ʱ��Ϊ0
	void tic();
	//���ͳ����ʱ��msg��Ϊ�գ�����dos�����ʾ����
	clock_t toc(string msg = "");

	//��ͣ��ʱ
	void turnOff();
	//�ָ���ʱ
	void turnOn();

private:
	//�洢ʱʹ�õĵ�λ�Ǻ���
	clock_t sum;
	clock_t start;
};

// ��һ���ļ���string�ķ�ʽ����
string ReadFile(const char* FileName);


// ��"data"�ļ��������
//   ��ȡ�ɹ�����true������false��ʾ�������������
bool GetTestData(string PID, int testId, string &in, string &out);

typedef pair<string,string> pss;

class JudgeData {
public:
	//data[i][j]: ��i��ĵ�j������, first�����룬second�����
	vector<vector<pss>> vvdata;

	JudgeData() {}

	// ͨ��һ���ļ�������
	JudgeData(string fileName);

	void Read(string fileName);

	//���ո�ʽ�����ݴ洢���ļ�
	void Save(string fileName);

private:
	vector<pss> AddOneProblem(string content);
};

string RemoveTailBlank(string in);

