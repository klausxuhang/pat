#include <iostream>
#include <vector>
using namespace std;

void up_n(long & sum,int n){
	sum += (n * 6);
	sum += 5;
}
void down_n(long& sum,int n){
	sum += (n * 4);
	sum += 5;
}

int main()
{
	long sum = 0;
	int n;
	vector<int> stairs;
	stairs.push_back(0);
	cin>>n;
	while(n--){
		int temp;
		cin>>temp;
		stairs.push_back(temp);
	}

	vector<int> floors;
	for (int i = 1; i < stairs.size(); ++i)
	{
		floors.push_back(stairs[i] - stairs[i-1]);
	}
	
	for(int i = 0; i<floors.size();++i){
		if(floors[i] > 0)
			up_n(sum,floors[i]);
		else
			down_n(sum,-floors[i]);
	}

	cout<<sum;
}