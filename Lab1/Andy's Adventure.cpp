#include <iostream>
#include <set>
#include <iterator>
using namespace std;
typedef long long lon;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	lon num,value,stone,count=0;
	cin >> num >> value;
	multiset<lon> s;
	multiset<lon>::iterator it1,it2,it3;
	
	for(int i=0;i<num;i++){
		cin >> stone;
		s.insert(stone);
	}
	
	for(it1=s.begin();it1!=prev(s.end(),2);it1++){
		if(*prev(it1,1)==*it1){
			continue;
		}
		it2 = next(it1,1);
		it3 = prev(s.end(),1);
		while(it2!=it3){
			if(*it2+*it3>value-*it1){
				it3--;
			}
			else if(*it2+*it3<value-*it1){
				it2++;
			}
			else{
				count++;
				if(*prev(it2,1)==*it2 && *next(it3,1)==*it3){
					count--;
				}
				//cout << *it1 << *it2 << *it3;
				it2++;
				if(it2==it3){
					break;
				}
				it3--;
				
			}
		}
	}
	if(count==0){
		cout << "FeiDooDoo_Zuo_Wei_Men";
	}
	else{
		cout << count ;
	}
	
}
