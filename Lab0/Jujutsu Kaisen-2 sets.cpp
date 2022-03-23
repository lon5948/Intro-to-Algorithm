#include <iostream>
#include <math.h>
#include <set>

using namespace std;

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
	int length,times,num,low,up;
	cin >> length >> times;
	set <int> s;
	set<int>::iterator it;
	set <int> dis;
	s.insert(0);
	s.insert(length);
	dis.insert(length);
	
	for(int i=0;i<times;i++){
		cin >> num;
		it = s.upper_bound(num);
		up = *it;
		low = *--it;
		//cout << up << " "<< low << endl; 
		s.insert(num);
		dis.erase(up-low);
		dis.insert(num-low);
		dis.insert(up-num);
	
		cout << *--dis.end()/2 << '\n';
	}
}
