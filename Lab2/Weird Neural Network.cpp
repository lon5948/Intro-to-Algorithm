#include <iostream>
#include <vector>

using namespace std;
typedef long long lon;

class Node{
	public:
		lon data;
		Node *left;
		Node *right;
		
		Node(lon d){
			left = NULL;
			right = NULL;
			data = d;
		}
};

int postorder(Node *root);

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
	vector<Node*> da;
  	vector<lon> pa;
	
	lon N,data,parent;
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> data;
		Node *newnode = new Node(data);
		da.push_back(newnode);
	}
	
	for(int i=1;i<N;i++){
		cin >> parent;
		pa.push_back(parent);
	}
	
	for(int i=0;i<N-1;i++){
		if(da[pa[i]-1]->left == NULL){
			da[pa[i]-1]->left = da[i+1];
		}
		else{
			da[pa[i]-1]->right = da[i+1];
		}
	} 
	cout << postorder(da[0]) << '\n'; 
} 

int postorder(Node *root){
	lon a,b,num;
	
	if(root->left==NULL){
		return root->data;
	}
	a = postorder(root->left);
	b = postorder(root->right);

	num = (root->data*(a+b))%1000000007;
		
	return num;
}
