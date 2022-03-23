#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
	int m,n,a,money;
	double r,tax;
	vector<pair<int,double>> vec;
	cin >> n;
	 
	for(int i=0;i<n;i++){
		cin >> a >> r;
		vec.push_back(make_pair(a,r));	
	}
	
	cin >> m;
	
	for(int i=0;i<m;i++){
		tax=0;
		cin >> money;
		for(int j=vec.size()-1;j>=0;j--){
			if(money>=vec[j].first){
				tax += (money-vec[j].first+1)*vec[j].second*10000000;
				money = vec[j].first-1;
			} 
		} 
		cout << fixed <<setprecision(7) << tax/10000000 << '\n'; 
	}
}
