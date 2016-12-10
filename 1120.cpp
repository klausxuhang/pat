#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
	
int main()
{
	int n;
	cin >> n;
	vector<string> str_data;
	while (n--) {
		string temp;
		cin >> temp;
		str_data.push_back(temp);
	}
	set<int> unique_da;
	for (int i = 0; i < str_data.size(); ++i) {
		int temp = 0;
		for (auto c : str_data[i]) {
			temp += (c - '0');
		}
		unique_da.insert(temp);
	}
	cout << unique_da.size();
	cout << endl;

	vector<int> int_data(unique_da.begin(), unique_da.end());
	for (int i = 0; i < int_data.size(); ++i) {
		for (int j = i + 1; j < int_data.size(); ++j) {
			if (int_data[i] > int_data[j]) {
				int temp = int_data[i];
				int_data[i] = int_data[j];
				int_data[j] = temp;
			}
		}
	}
	for (int i = 0; i < int_data.size(); ++i) {
		if (i == int_data.size() - 1) {
			cout << int_data[i];
			continue;
		}
		cout << int_data[i] << ' ';
	}
}