#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std; 
typedef unsigned long int lon;

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
	stack<lon> s;
	char a[10];
	lon num1,num2,ans;
	
	while(cin >> a){
		if(a[0]=='+'){
			num1 = s.top();
			s.pop();
			num2 = s.top();
			s.pop();
			s.push((num1+num2)%(1000000007));
		}
		else if(a[0]=='*'){
			num1 = s.top();
			s.pop();
			num2 = s.top();
			s.pop();
			s.push((num1*num2)%(1000000007));
		}
		else{
			s.push(atoi(a)%1000000007);
		}
	}
	ans = s.top()%(1000000007);
	cout << ans;
}
