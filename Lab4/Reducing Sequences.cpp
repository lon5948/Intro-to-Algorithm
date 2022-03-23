#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
typedef long long int lon;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int n;
	cin >> n;
	
	lon reward[n+1][n+1];
	lon weight[n+1];
	lon sum[n+1];
	sum[0] = 0;
	
	for(int i=1;i<=n;i++){
		cin >> weight[i];
		sum[i] = sum[i-1]+weight[i];
		for(int j=1;j<=n;j++){
			reward[i][j] = 0;
		}
	} 
	
	for(int len=3;len<=n;len+=2){
		for(int left=1;left+len-1<=n;left++){
			int right = left+len-1;
			for(int k=left+1;k<right;k+=2){
				if(reward[left][right]!=0){
					reward[left][right] = max(reward[left][right],reward[left][k-1]+reward[k+1][right]+(sum[right]-sum[k])*(sum[k-1]-sum[left-1])-(sum[k]-sum[k-1]));
				}
				else{
					reward[left][right] = reward[left][k-1]+reward[k+1][right]+(sum[right]-sum[k])*(sum[k-1]-sum[left-1])-(sum[k]-sum[k-1]);
				}
			}	
			reward[left][right] = max(reward[left][right],reward[left+1][right-1]+(sum[right]-sum[right-1])*(sum[left]-sum[left-1])-(sum[right-1]-sum[left]));
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << reward[i][j] << " ";
		}
		cout << endl;
	} 
	
	return 0;
}
