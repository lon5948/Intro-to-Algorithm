#include <iostream>
#include <queue>
using namespace std;

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
	int times,id,po;
	cin >> times;
	queue <pair<int,int>> q;
	
	for(int i=0;i<times;i++){
		cin >> id >> po;
		q.push(make_pair(id,po));
	}
	
	while(!q.empty()){
		
		cout << q.front().first << '\n';
		
		if(--q.front().second>0){
			q.push(make_pair(q.front().first,q.front().second));
		}
		q.pop();
	}
}
