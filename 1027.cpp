#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> tran_10_to_13(istream &in);
char tran(int);

int main()
{
	vector<string> vec_of_str;
	vec_of_str = tran_10_to_13(cin);
	cout<<'#';
	for(auto c:vec_of_str)
		cout<<c;
	cout<<endl;
}

vector<string> tran_10_to_13(istream &in){
	if(!in){
		cerr<<"wrong!"<<endl;
		exit(-1);
	}
	vector<string> _13dec;
	int temp;
	while(in>>temp){
		int shi = temp / 13;
		int ge = temp % 13;
		string _13str = "";
		if(shi > 9)
			_13str += tran(shi);
		else
			_13str += (shi + '0');
		if(ge > 9)
			_13str += tran(ge);
		else
			_13str += (ge + '0');
		_13dec.push_back(_13str);
	}
	return _13dec;
}
char tran(int n){
	if(n == 10)
		return 'A';
	else if(n == 11)
		return 'B';
	else if(n == 12)
		return 'C';
}