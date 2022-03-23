#include <iostream>
#include <map>
#include <queue>
using namespace std; 

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
	int times,check,type,num;
	cin >> times;
	map < int , priority_queue<int,vector<int>,greater<int> > > m;
	map < int,priority_queue<int,vector<int>,greater<int> > >::iterator it;
	for(int i=0;i<times;i++){
		cin >> check >> type;
	    it = m.find(type); 
		if(check==1){
			cin >> num;
			if(it!=m.end()){
				it->second.push(num);	
			}
			else{
				priority_queue<int,vector<int>,greater<int> > pq;
				pq.push(num);
				m.insert(make_pair(type,pq));
				pq.pop();
			}  
		}	
		else if(check==2){
			if(it!=m.end()){
				cout << it->second.top() << '\n';
				it->second.pop();
				if(it->second.empty()){
					m.erase(it);
				}	
			}
			else{ 
				cout << "-1" << '\n';
			}
		}
	} 
}
