#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct{
	string username;
	string password;
	int flag;
}pass_me;

int main()
{
	vector<pass_me> vpa;
	int n;
	cin>>n;
	string username;
	string password;
	int flag;
	pass_me temp;
	while(n--){
		cin>>temp.username;
		cin>>temp.password;
		temp.flag = 0;
		vpa.push_back(temp);
	}

	for(int i = 0; i < vpa.size(); ++i){
		for(auto &c:vpa[i].password){
			if(c == '1'){
				c = '@';
				vpa[i].flag = 1;
			}
			if(c == '0'){
				c = '%';
				vpa[i].flag = 1;
			}
			if(c == 'O'){
				c = 'o';
				vpa[i].flag = 1;
			}
			if(c == 'l'){
				c = 'L';
				vpa[i].flag = 1;
			}
		}
	}
	int sum = 0;
	for(int i = 0; i<vpa.size();++i){
		sum += vpa[i].flag;
	}
	if(sum == 0){
		if(vpa.size() == 1)
			cout<<"There is 1 account and no account is modified";
		else if(vpa.size() > 1)
			cout<<"There are "<<vpa.size()<<" accounts and no account is modified";
		return 0;
	}
	cout<<sum<<endl;
	for(int i = 0; i< vpa.size(); ++i){
		if(vpa[i].flag == 1)
			cout<<vpa[i].username<<" "<<vpa[i].password<<endl;
	}
	return 0;
}