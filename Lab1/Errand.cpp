#include <iostream>
#include <set>
using namespace std;
typedef long long int lon; 

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
  	lon n,l,k,weight,time=0;
  	multiset <lon> s;
  	multiset <lon>::reverse_iterator re;
  	cin >> n >> l >> k;
  	for(int i=0;i<n;i++){
  		cin >> weight;
  		s.insert(weight);
	}
	for(re=s.rbegin();re!=s.rend();re++){
		if(*s.begin()+*re<=l){
			time += 2*k;
			if(re==--s.rend()){
				break;
			}
			s.erase(s.begin());
		}
		else{
			time += 2*k;
		}
	}
	cout << time << '\n';
}
