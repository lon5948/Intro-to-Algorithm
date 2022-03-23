#include <iostream>
#include <math.h>
#include <set>

using namespace std;

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
	int length,times,num,a,b,dis=0,ra=0,rb=0;
	cin >> length >> times;
	set <int> s;
	set <int>::iterator it;
	s.insert(0);
	s.insert(length);
	
	for(int i=0;i<times;i++){
		cin >> num;
		s.insert(num);
		dis=0;
		for(it=s.begin();it!=--s.end();){
			a = *it;
			b = *++it;
			if(floor((b-a)/2>dis)){
				dis = floor((b-a)/2);
			}
		}	
		cout << dis << '\n';
	}
}
