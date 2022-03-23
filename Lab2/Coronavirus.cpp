#include <iostream>

using namespace std;
typedef long long lon;

lon powint(lon a,lon x);

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
	lon a,b,t,N,x,ax,ans;
	cin >> a >> b >> N;
	t = b/(a-1);
	
	for(int i=0;i<N;i++){
		cin >> x;
		ax = powint(a,x-1);
		ans = (ax + (ax-1)*t)%1000000007;
		if(ans<0){
			ans += 1000000007;
		}
		cout << ans << '\n';
	}
	
	return 0;
} 

lon powint(lon a,lon x){
	lon sum=1;
	
	while(x>0){
		
		if(x%2==1){
			sum *= a;
			sum %= 1000000007;
			x--;
		}
	
		x /= 2;
		a = a*a;
		a %= 1000000007;
	}
	
	return sum;
}
