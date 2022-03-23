#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lon;

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
  	vector<pair<lon,lon>> v;
  	vector<pair<lon,lon>>::iterator it,low;
	lon n,k,member=0,c,p;
	long double left=0,right=0,mid;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> c >> p;
		if(right<c/(p+1)){
			right = c/(p+1);
		}
		if(c>p){
			v.push_back(make_pair(c,p));	
		}
		
	} 
	mid = (left+right)/2;
	
	do{
		member=0;
		for(it=v.begin();it!=v.end();it++){
			if(lon(it->first/mid)-it->second>0){
				member += lon(it->first/mid)-it->second;
			}	
			if(member>=k){
				break;
			}
		}
		
		if(member>=k){
			left = mid;
		}
		else{
			right = mid;
		}
		mid = (left+right)/2;
		
	}while(right-left>=0.000001);
	
	
	cout << fixed << setprecision(7) << mid << '\n';
}
