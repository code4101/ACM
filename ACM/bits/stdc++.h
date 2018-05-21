//VS并没有bits/stdc++.h文件，所以这里伪造一个，顺便把一些方便调试的代码写上去

#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
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
#include <ctime>
using namespace std;

#define TRACE(v) cout << #v << ": " << v << "\n";

#define COUT(v) cout << #v << ": " << v << "\n";

#define DEBUG_TAG printf("%s: %d\n", __FILE__, __LINE__);

// encloser: use encloser.begin() char to left, encloser.rbegin() char to right, can be empty
// make sure the element type has "ostream <<" method
template<typename InputIterator>
string GetArrayMsg(InputIterator first, const InputIterator last,
	const string delimiter = ", ", string encloser = "") {
	if (first == last) {
		return encloser;
	}

	stringstream ss;
	if (!encloser.empty()) ss << *encloser.begin();
	ss << *first;
	++first;
	while (first != last) {
		ss << delimiter << *first;
		++first;
	}
	if (!encloser.empty()) ss << *encloser.rbegin();

	return ss.str();
}

/* auto cout(or other ostream) type for convenient
  need previous function: GetArrayMsg

  support type and format:
  (make sure the type 'T' has "ostream <<" method)
    vector<T>: [1, 2, 3]
	map<T1, T2>: {a:1, b:2, c:3}
	set<T>: {1, 2, 3}
*/
namespace std {
	
	// vector<T>
	template<typename T>
	ostream& operator<< (ostream& out, const vector<T>& v) {
		out << GetArrayMsg(v.begin(), v.end(), ", ", "[]");
		return out;
	}

	// map<T1, T2>
	template<typename T1, typename T2>
	ostream& operator<< (ostream& out, const map<T1, T2>& v) {
		if (v.empty()) {
			out << "{}";
			return out;
		}
		auto it = v.begin();
		out << '{' << (it->first) << ":" << (it->second);
		for (++it; it != v.end(); ++it) {
			out << ", " << (it->first) << ":" << (it->second);
		}
		out << '}';
		return out;
	}

	// set<T>
	template<typename T>
	ostream& operator<< (ostream& out, const set<T>& v) {
		out << GetArrayMsg(v.begin(), v.end(), ", ", "{}");
		return out;
	}
}
