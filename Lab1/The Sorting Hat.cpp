#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class student{
	public:
		string name;
		int num[4];
		int house[4];
};

bool cmp(student a,student b){
	if(a.num[a.house[0]]!=b.num[b.house[0]]){
		return a.num[a.house[0]]>b.num[b.house[0]];
	}
	else if(a.num[a.house[1]]!=b.num[b.house[1]]){
		return a.num[a.house[1]]>b.num[b.house[1]];
	}
	else if(a.num[a.house[2]]!=b.num[b.house[2]]){
		return a.num[a.house[2]]>b.num[b.house[2]];
	}
	else if(a.num[a.house[3]]!=b.num[b.house[3]]){
		return a.num[a.house[3]]>b.num[b.house[3]];
	}	
	else{
		return a.name<b.name;
	}	
}


int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
  	
  	int n,ginp,hinp,rinp,sinp,max;
	string nameinp,sg,sh,sr,ss;
	int arr[4][4];
	vector<student> vecg;
	vector<student> vech;
	vector<student> vecr;
	vector<student> vecs;
	cin >> n;
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			char ch;
			cin >> ch;
			if(ch=='G') arr[i][j] = 0;
			else if(ch=='H') arr[i][j] = 1;
			else if(ch=='R') arr[i][j] = 2;
			else if(ch=='S') arr[i][j] = 3;
		}
	}
	for(int i=0;i<n;i++){
		student cla;
		cin >> nameinp >> ginp >> hinp >> rinp >> sinp;
		cla.name = nameinp;
		cla.num[0] = ginp;
		cla.num[1] = hinp;
		cla.num[2] = rinp;
		cla.num[3] = sinp;
		max = ginp;
		if(hinp>max) max = hinp;
		if(rinp>max) max = rinp;
		if(sinp>max) max = sinp;
		
		if(max==ginp){
			cla.house[0] = arr[0][0];
			cla.house[1] = arr[0][1];
			cla.house[2] = arr[0][2];
			cla.house[3] = arr[0][3];
			vecg.push_back(cla);
		}
		else if(max==hinp){
			cla.house[0] = arr[1][0];
			cla.house[1] = arr[1][1];
			cla.house[2] = arr[1][2];
			cla.house[3] = arr[1][3];
			vech.push_back(cla);
		}
		else if(max==rinp){
			cla.house[0] = arr[2][0];
			cla.house[1] = arr[2][1];
			cla.house[2] = arr[2][2];
			cla.house[3] = arr[2][3];
			vecr.push_back(cla);
		}
		else if(max==sinp){
			cla.house[0] = arr[3][0];
			cla.house[1] = arr[3][1];
			cla.house[2] = arr[3][2];
			cla.house[3] = arr[3][3];
			vecs.push_back(cla);
		}
	}	
	
	if(vecg.empty()){
		cout << "GRYFFINDOR: ";
		cout << "NO NEW STUDENTS" << '\n';
	}
	else if(vecg.size()==1){
		cout << "GRYFFINDOR: " << '\n';
		cout << vecg[0].name << '\n';
	}
	else{
		cout << "GRYFFINDOR: " << '\n';
		sort(vecg.begin(),vecg.end(),cmp);
		for(int i=0;i<vecg.size();i++){
			cout << vecg[i].name << '\n';
		}
	}

	if(vech.empty()){
		cout << "HUFFLEPUFF: ";
		cout << "NO NEW STUDENTS" << '\n';
	}
	else if(vech.size()==1){
		cout << "HUFFLEPUFF:" << '\n';
		cout << vech[0].name << '\n';
	}
	else{
		cout << "HUFFLEPUFF:" << '\n';
		sort(vech.begin(),vech.end(),cmp);
		for(int i=0;i<vech.size();i++){
			cout << vech[i].name << '\n';
		}
	}

	if(vecr.empty()){
		cout << "RAVENCLAW: ";
		cout << "NO NEW STUDENTS" << '\n';
	}
	else if(vecr.size()==1){
		cout << "RAVENCLAW:" << '\n';
		cout << vecr[0].name << '\n';
	}
	else{
		cout << "RAVENCLAW:" << '\n';
		sort(vecr.begin(),vecr.end(),cmp);
		for(int i=0;i<vecr.size();i++){
			cout << vecr[i].name << '\n';
		}
	}
 
	if(vecs.empty()){
		cout << "SLYTHERIN: ";
		cout << "NO NEW STUDENTS" << '\n';
	}
	else if(vecs.size()==1){
		cout << "SLYTHERIN:" << '\n';
		cout << vecs[0].name << '\n';
	}
	else{
		cout << "SLYTHERIN:" << '\n';
		sort(vecs.begin(),vecs.end(),cmp);
		for(int i=0;i<vecs.size();i++){
			cout << vecs[i].name << '\n';
		}
	}
	
	return 0;
}
