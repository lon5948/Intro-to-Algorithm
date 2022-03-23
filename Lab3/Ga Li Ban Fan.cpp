#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int lon;

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
	lon order,rm,a,num,p,m,size;
	lon money[7];
	cin >> order;
	
	for(int i=0;i<order;i++){
		cin >> rm;
		priority_queue<lon> pq;
		for(int k=0;k<7;k++){
			money[k]=0;	
		}
		
		for(lon j=0;j<rm;j++){
			cin >> num;
			for(int k=0;k<7;k++){
				cin >> a;
				money[k] += a;
				
				if(a!=0){
					switch(k){
						case 0:
							num -= 1000*a;
							break;
						case 1:
							num -= 500*a;
							break;
						case 2:
							num -= 100*a;
							break;
						case 3:
							num -= 50*a;
							break;
						case 4:
							num -= 10*a;
							break;
						case 5:
							num -= 5*a;
							break;
						case 6:
							num -= 1*a;
							break;
					}
				}
			}
			if(num!=0){
				pq.push(-num);
			}
		}
		size = pq.size();
		if(size==0){
			cout << "Yes" << '\n';
			continue;
		}
		for(lon j=0;j<size;j++){
			p = pq.top();
			pq.pop();
			if(p>=1000 && money[0]!=0){
				m = min(money[0],p/1000);
				p -= m*1000;
				money[0] -= m;
			}
			if(p>=500 && money[1]!=0){
				m = min(money[1],p/500);
				p -= m*500;
				money[1] -= m;
			}
			if(p>=100 && money[2]!=0){
				m = min(money[2],p/100);
				p -= m*100;
				money[2] -= m;
			}
			if(p>=50 && money[3]!=0){
				m = min(money[3],p/50);
				p -= m*50;
				money[3] -= m;
			}
			if(p>=10 && money[4]!=0){
				m = min(money[4],p/10);
				p -= m*10;
				money[4] -= m;
			}
			if(p>=5 && money[5]!=0){
				m = min(money[5],p/5);
				p -= m*5;
				money[5] -= m;
			}
			if(p>=1 && money[6]!=0){
				m = min(money[6],p/1);
				p -= m*1;
				money[6] -= m;
			}
			
			if(p!=0){
				cout << "No" << '\n';
				break;
			}
			else if(pq.empty()){
				cout << "Yes" << '\n';
			}
		}
	}
}
