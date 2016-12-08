#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <string>
using namespace std;

long getcount(string );
void output(long);

int main()
{
	string input;
	cin>>input;
	long sum;
	sum =  getcount(input);
	output(sum);
	return 0;
}

long getcount(string input){
	vector<int> vi;
	for(auto& c: input)
		vi.push_back(c-'0');
	long sum = 0;
	for(auto& c: vi)
		sum += c;
	return sum;
}

void output(long sum){
	if(sum == 0){
		cout<<"zero";
		return;
	}
	map<int,string> dtos = {{0,"zero"},{1,"one"},{2,"two"},{3,"three"},{4,"four"},{5,"five"},{6,"six"},{7,"seven"},{8,"eight"},{9,"nine"}};
	deque<string> ds;
	while(sum){
		ds.push_front(dtos[sum % 10]);
		sum /= 10;
	}
	cout<<ds[0];
	if(ds.size() == 1)
		return;
	for(int i = 1; i < ds.size(); ++i)
		cout<<' '<<ds[i];
}