#include <iostream>
#include <vector>
using namespace std;
void awkwardness(int il,int ir,int pl,int pr,int &count);

vector<int> age;
vector<int> inorder;
vector<int*> inorderp;
vector<int> postorder;
	
int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
  	int n,a,count=0; 
  	cin >> n;
  	
  	age.resize(n);
  	inorder.resize(n);
	inorderp.resize(n+1);
	postorder.resize(n);
  	
  	for(int i=0;i<n;i++){
  		cin >> age[i];
	}
	
	for(int i=0;i<n;i++){
  		cin >> inorder[i];
  		inorderp[inorder[i]] = &inorder[i];
	}
	
	for(int i=0;i<n;i++){
  		cin >> postorder[i];
	}
	
	awkwardness(0,n-1,0,n-1,count);
	
	cout << count ;
} 

void awkwardness(int il,int ir,int pl,int pr,int &count){
	if(ir<=il)
		return;
		
	int rootindex,lsize,rsize,lindex,rindex;
	rootindex = postorder[pr];
	lsize = inorderp[rootindex] - inorderp[inorder[il]];
	rsize = inorderp[inorder[ir]] - inorderp[rootindex];
	
	if(lsize!=0){
		lindex = postorder[pl+lsize-1];
		if(age[rootindex-1]<age[lindex-1]){
			count++;
		}
	}
	
	if(rsize!=0){
		rindex = postorder[pr-1];
		if(age[rootindex-1]<age[rindex-1]){
			count++;
		}
	}
	
	awkwardness(il,il+lsize-1,pl,pl+lsize-1,count);
	
	awkwardness(il+lsize+1,ir,pl+lsize,pr-1,count);
	
}
