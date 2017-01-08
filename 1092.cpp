#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	multiset<char> mset; 
	string s1;
	cin>>s1;
	for(auto c:s1)
		mset.insert(c);
	int sum = mset.size();
	// cout<<sum<<endl;
	int i = 0;
	string s2;
	cin>>s2;
	for(auto c:s2){
		++i;
		auto it = mset.find(c);
		if(it != mset.end())
			mset.erase(it);
	}
	// cout<<i<<endl;
	int after_erase = mset.size();
	// cout<<after_erase<<endl;
	if(after_erase + i == sum){
		cout<<"Yes "<<after_erase<<endl;
	}else{
		cout<<"No ";
		cout<<after_erase+i-sum<<endl;
	}
}
