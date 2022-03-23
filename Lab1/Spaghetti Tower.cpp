#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lon;

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
	vector<lon> vec;
	vector<lon>::iterator up,low;
	lon n,k,s,q,x,l,count,times,min;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> s;
		vec.push_back(s);
	}
	sort(vec.begin(),vec.end());
	cin >> q;
	for(int i=0;i<q;i++){
		cin >> x >> l;
		if(l>k*x){
			min = k*x;
		}
		else{
			min = l;
		}
		count = 0;
		times = 0;
		for(int i=0;i<=min;i+=x){
			low = lower_bound(vec.begin(),vec.end(),i);
			if(i+x-1<min){ //-1
				up = upper_bound(vec.begin(),vec.end(),i+x-1);	
			}
			else{
				up = upper_bound(vec.begin(),vec.end(),min);	
			}
			count += (up-low)*times;
			times++;
		}
		cout << count << '\n';
	}
	return 0;
}
