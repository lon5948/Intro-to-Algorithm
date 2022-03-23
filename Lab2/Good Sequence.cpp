#include <iostream>
#include <algorithm>
using namespace std;
typedef long long lon;
//should find median instead of average

lon GoodSeq(lon *arr,lon left,lon right);

int main(){
	cin.tie();
	cin.sync_with_stdio(0);
	
	lon n,num,op;
	cin >> n;
	lon arr[n];
	
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	op = GoodSeq(arr,0,n-1);
	cout << op;
} 

lon GoodSeq(lon *arr,lon left,lon right){
	lon middle,lsize,rsize,m,medl,medr,op1=0,op2=0;
	middle = (left+right)/2;
	lsize = middle-left+1;
	rsize = right-middle;
	lon L[lsize],R[rsize];
	
	if(right-left<=1){
		return 0;
	}
	else{
		for(int i=0;i<lsize;i++){
			L[i] = arr[left+i];
		}
		
		nth_element(L,L+(lsize-1)/2,L+lsize);
		medl = L[(lsize-1)/2];
		//cout << "left: " << left << endl;
		//cout << "middle: " << middle << endl;
		//cout << "right: " << right << endl;
		//cout << "medl: " << medl << endl;
		for(int i=0;i<lsize;i++){
			if(arr[left+i]>medl){
				op1 += (arr[left+i]-medl);
				//cout << "op1a: " << op1 << endl;
			}
			else{
				op1 += (medl-arr[left+i]);
				//cout << "op1b: " << op1 << endl;
			}
		}
		op1 += GoodSeq(arr,middle+1,right);
		//cout << "-------------------------------" << endl; 
		
		for(int i=0;i<rsize;i++){
			R[i] = arr[middle+1+i];
		}
		nth_element(R,R+(rsize+1)/2,R+rsize);
		medr = R[(rsize-1)/2];
		//cout << "medr: " << medr << endl;
		for(int i=0;i<rsize;i++){
			if(arr[middle+1+i]>medr){
				op2 += (arr[middle+1+i]-medr);
				//cout << "arr[middle+1+i]: " << arr[middle+1+i] << endl; 
				//cout << "op2a: " << op2 << endl;
			}
			else{
				op2 += (medr-arr[middle+1+i]);
				//cout << "arr[middle+1+i]: " << arr[middle+1+i] << endl;
				//cout << "op2b: " << op2 << endl;
			}
		}
		op2 += GoodSeq(arr,left,middle);
	}
	
	if(op1<op2){
		return op1;
	}
	else{
		return op2;
	}
}
