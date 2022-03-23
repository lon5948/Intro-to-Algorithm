#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>
#include <math.h>
using namespace std;

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
	vector<int> v;
	v.push_back(1);
	int N,p;
	cin >> N;
	
	for(int i=0;i<N;i++){
		vector<int> add;
		p = pow(2,i);
		reverse(v.begin(),v.end());
		add.assign(v.begin(),v.end());
		for(int j=0;j<add.size();j++){
			add[j] += p;	
		}
		v.insert(v.begin(),add.rbegin(),add.rend());
	}
	
	for(int i=0;i<v.size();i++){
		cout << v[i] << " ";
	}
}
