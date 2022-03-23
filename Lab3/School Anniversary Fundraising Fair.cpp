#include <iostream>
#include <queue>
using namespace std;
typedef long long lon;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	priority_queue<pair<lon,lon>,vector<pair<lon,lon> >,greater<pair<lon,lon> > >pq;
	lon num,value,start,end,fir,sec,max,count=0;
	
	cin >> num >> value >> start >> end;
	
	for(int i=0;i<num;i++){
		cin >> fir >> sec;
		pq.push(make_pair(fir,sec));
	}
	
	while(!pq.empty()){
		if(pq.top().second<=start){
			pq.pop();
		}
		else if(pq.top().first<=start && pq.top().second>=end){
			count++;
			start = end;
			break;
		}
		else if(pq.top().first<=start){
			count++;
			max = pq.top().second;
			pq.pop();
			while(pq.top().first<=start){
				if(pq.top().second>max){
					max = pq.top().second;
				}
				pq.pop();
			}
			start = max;
		}
		else{
			break;
		}
	}
	if(start<end){
		cout << 0 << '\n';
	}
	else{
		cout << value*count << '\n';
	}
	
}
