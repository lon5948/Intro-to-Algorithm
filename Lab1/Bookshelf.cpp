#include <iostream>
#include <map>

using namespace std;

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
	int n,m,num,a;
	cin >> n >> m;
	map <int,int> ma;
	map <int,int> ::iterator it;
	for(int i=0;i<n;i++){
		cin >> num;
		ma.insert(make_pair(num,i));		
	} 
	
	for(int i=0;i<m;i++){
		cin >> a;
		it = ma.find(a);
		if(it!=ma.end()){
			cout << it->second << '\n';
		}
		else{
			cout << "-1" << '\n';
		}
	}
}
