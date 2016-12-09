#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef struct person {
	string name;
	string sign_in;
	string sign_out;
	person * next;
} person, *pper;

void read(pper P);
void out(pper P);
int main()
{
	pper P = new person;
	read(P);
	out(P);
	return 0;
}

void read(pper P) {
	pper pre = P;
	int n;
	cin >> n;
	while (n--) {
		pper temp = new person;
		cin >> temp->name >> temp->sign_in >> temp->sign_out;
		temp->next = NULL;
		pre->next = temp;
		pre = temp;
	}
}

void out(pper P) {
	map<string,pper> converse;
	pper pre = P;
	typedef struct {
		pper p;
		int hour;
		int min;
		int sec;
	}time_now;
	vector<time_now> times_in;
	vector<string> signin;
	while (pre->next) {
		signin.push_back(pre->next->sign_in);
		converse[pre->next->sign_in] = pre->next;
		pre = pre->next;
	}
	for (int i = 0; i < signin.size(); ++i) {
		time_now temp;
		temp.p = converse[signin[i]];
		int h = (signin[i][0] - '0') * 10 + (signin[i][1] - '0');
		temp.hour = h;
		int m = (signin[i][3] - '0') * 10 + (signin[i][4] - '0');
		temp.min = m;
		int s = (signin[i][6] - '0') * 10 + (signin[i][7] - '0');
		temp.sec = s;
		times_in.push_back(temp);
	}

	time_now in = times_in[0];
	for (int i = 1; i < times_in.size(); ++i) {
		if (times_in[i].hour < in.hour) {
			in = times_in[i];
		}
		else if (times_in[i].hour == in.hour) {
			if (times_in[i].min < in.min) {
				in = times_in[i];
			}
			else if (times_in[i].min == in.min) {
				if (times_in[i].sec < in.sec)
					in = times_in[i];
			}
		}
	}

	cout<<in.p->name;
	cout << ' ';

	vector<time_now> times_out;
	vector<string> signout;
	pper pree = P;
	while (pree->next) {
		signout.push_back(pree->next->sign_out);
		converse[pree->next->sign_out] = pree->next;
		pree = pree->next;
	}
	for (int i = 0; i < signout.size(); ++i) {
		time_now temp;
		temp.p = converse[signout[i]];
		int h = (signout[i][0] - '0') * 10 + (signout[i][1] - '0');
		temp.hour = h;
		int m = (signout[i][3] - '0') * 10 + (signout[i][4] - '0');
		temp.min = m;
		int s = (signout[i][6] - '0') * 10 + (signout[i][7] - '0');
		temp.sec = s;
		times_out.push_back(temp);
	}

	time_now out = times_out[0];
	for (int i = 1; i < times_out.size(); ++i) {
		if (times_out[i].hour > out.hour) {
			out = times_out[i];
		}
		else if (times_out[i].hour == out.hour) {
			if (times_out[i].min > out.min) {
				out = times_out[i];
			}
			else if (times_out[i].min == out.min) {
				if (times_out[i].sec > out.sec)
					out = times_out[i];
			}
		}
	}
	cout << out.p->name;
}