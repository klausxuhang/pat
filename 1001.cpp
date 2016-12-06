#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int a,b;
	int flag = 0;
	cin>>a;
	cin>>b;
	int c = a + b;
	deque<int> vi;
	if (c == 0){
		cout<<'0';
		return 0;
	}
	if(c < 0){
		c = -c;
		flag = 1;
	}
	if(c < 1000){
		while(c){
			int d = c % 10;
			vi.push_front(d);
			c /= 10;
		}
		if(flag)
			cout<<'-';
		for(int index = 0; index < vi.size(); ++index){
			cout<<vi[index];
		}
    }
    else if(c >= 1000 && c < 10000){
		while(c){
			int d = c % 10;
			vi.push_front(d);
			c /= 10;
		}
		if(flag)
			cout<<'-';
		cout<<vi[0];
		cout<<',';
		for(int i = 1; i < vi.size(); ++i)
			cout<<vi[i];
    }else if(c >= 10000 && c <= 100000){
		while(c){
			int d = c % 10;
			vi.push_front(d);
			c /= 10;
		}
		if(flag)
			cout<<'-';
		for(int i = 0; i<2; ++i)
			cout<<vi[i];
		cout<<',';
		for(int i = 2; i<vi.size(); ++i)
			cout<<vi[i];
    }else if(c >= 100000 && c<1000000){
		while(c){
			int d = c % 10;
			vi.push_front(d);
			c /= 10;
		}
		if(flag)
			cout<<'-';
		for(int i = 0; i<3;++i)
			cout<<vi[i];
		cout<<',';
		for(int i = 3; i< vi.size(); ++i)
			cout<<vi[i];
    }else if(c >= 1000000 && c <10000000){
		while(c){
			int d = c % 10;
			vi.push_front(d);
			c /= 10;
		}
		if(flag)
			cout<<'-';
		cout<<vi[0];
		cout<<',';
		for(int i = 1; i< 4;++i)
			cout<<vi[i];
		cout<<',';
		for(int i = 4; i< vi.size(); ++i)
			cout<<vi[i];
    }
}