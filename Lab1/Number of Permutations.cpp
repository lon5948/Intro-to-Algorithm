#include <iostream>
#include <queue>
using namespace std;
typedef long long int lon;

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
  	lon n,total=1,c,count=0;
  	priority_queue <int, vector<int>, greater<int> > pq;
  	cin >> n;
  	for(int i=0;i<n;i++){
  		cin >> c;
  		if(c>n)
			c = n; 
  		pq.push(c);
	}
	
	for(int i=0;i<n;i++){
  		total *= ((pq.top()-count)%1000000007);
  		pq.pop();
  		total %= 1000000007;
		count++;
	}
	
	cout << total << '\n';
}
