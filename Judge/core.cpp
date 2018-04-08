#include "core.h"

string Format(const string fmt_str, ...) {
	int final_n, n = ((int)fmt_str.size()) * 2; /* Reserve two times as much as the length of the fmt_str */
	string str;
	unique_ptr<char[]> formatted;
	va_list ap;
	while (1) {
		formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
		strcpy(&formatted[0], fmt_str.c_str());
		va_start(ap, fmt_str);
		final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
		va_end(ap);
		if (final_n < 0 || final_n >= n)
			n += abs(final_n - n + 1);
		else
			break;
	}
	return string(formatted.get());
}

CTime::CTime(clock_t _sum) {
	sum = _sum;
}

void CTime::tic() {
	start = clock();
}

clock_t CTime::toc(string msg)  {
	turnOff();

	long long min, sec, ms = sum * 1000 / CLOCKS_PER_SEC;
	long long ms_ = ms;
	if (msg != "") {
		sec = (ms / 1000) % 60;
		min = ms / 60000;
		ms %= 1000;

		cout << msg + "��ʱ ";
		if (min) cout << min << " ���� ";
		if (sec) cout << sec << " �� ";
		cout << ms << " ����" << endl;
	}

	turnOn();
	return ms_;
}

void CTime::turnOff() {
	if (start == -1) return;
	sum += clock() - start;
	//��-1��ʾ��ͣ��ʱ
	start = -1;
}

void CTime::turnOn() {
	if (start == -1) start = clock();
}

string ReadFile(const char* FileName) {
	int k;
	string s;
	FILE *f = fopen(FileName, "r");

	while ((k = getc(f)) != EOF)
		s = s + (char)k;

	fclose(f);

	return s;
}

std::string RemoveTailBlank(string in) {
	in.erase(in.find_last_not_of("\r\n")+1); //"\r\n"Ҳ���Ըĳ�" \n\r\t"
	return in;
}

JudgeData::JudgeData(string fileName) {
	Read(fileName);
}

void JudgeData::Read(string fileName) {
	vvdata.clear();
	string content = ReadFile(fileName.c_str());

	string pid = "### Promblem A ###";
	size_t spos, epos; // start position, end position
	while (spos = content.find(pid), spos != string::npos) {
		pid[13] += 1; // 'A' to 'B', 'C', 'D' ...
		epos = content.find(pid);
		if (epos == string::npos) epos = content.size();
		vvdata.push_back(AddOneProblem(content.substr(spos, epos - spos)));
	}
}

void JudgeData::Save(string fileName) {
	ofstream fout(fileName);
	int n = vvdata.size();
	rep(i,n) {
		if (i) fout << "\n\n";
		fout << "### Promblem " << char('A' + i) << " ###\n";

		vector<pss> &test = vvdata[i];
		rep(j,test.size()) {
			fout << test[j].first << '\n';
			fout << "------------------------\n";
			fout << test[j].second << '\n';
			fout << "============�� " << j+1 << " ��============\n";
		}
	}

	fout.close();
}

std::vector<pss> JudgeData::AddOneProblem(string content) {
	//[]��ʼ��
	istringstream ss(content);
	vector<pss> vdata;
	string line, firstLine, in, out;
	getline(ss, line); // remove title

	//[]�������ݸ�ʽ
	vector<string> lines;
	getline(ss, firstLine);
	string logo1, logo2; // ��5���ַ�ǰ׺��ʾ�ָ���
	if (firstLine == "input") { // ��input, output��ʽ��ȡ����
		logo1 = "outpu"; logo2 = "input";
	}
	else { // ��-----,=====�ĸ�ʽ����
		logo1 = "-----"; logo2 = "=====";
		in = firstLine + '\n';
	}

	//[]��ȡ����
	while (getline(ss, line)) {
		while (ss && line.substr(0, 5) != logo1) {
			in += line + '\n';
			getline(ss, line);
		}
		while (getline(ss, line) && line.substr(0, 5) != logo2) {
			out += line + '\n';
		}
		//ȥ��ĩβ�Ļ��з�
		in = RemoveTailBlank(in);
		out = RemoveTailBlank(out);
		if (in == "" && out == "") continue;
		vdata.push_back(pss(in, out));
		in = out = "";
	}
	return vdata;
}
