#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int num,n,count=0,bit,size,many;
	string str,word;
	cin >> n;
	map<string,int> m;
	map<string,int>::iterator it;
	map< string,vector<string> > name;
	set< pair<int,string> > s;
	set< pair<int,string> >::iterator s1,s2;
	vector<string> v;
	v.resize(n);
	getline(cin,str);
	
	for(int i=0;i<n;i++){
		getline(cin,str);
		str += ' ';
		v[i] = str;
		word = "";
		
		for(int j=0;j<str.size();j++){
			if(str[j] != ' '){
				word += str[j];
			}
			else{
				it = m.find(word);
				if(it!=m.end()){
					it->second++;
				}
				else{
					vector<string> vec;
					vec.push_back(word);
					m.insert(make_pair(word,1));
					name.insert(make_pair(word,vec));
				}
				word = "";
			}
		}
	}
	
	size = m.size();
	bit = ceil(log2(size));
	
	for(it=m.begin();it!=m.end();it++){
		s.insert(make_pair(it->second,it->first));
		it->second = 0;
	}
	
	while(s.size()!=1){
		s1 = s.begin();
		s2 = ++s.begin();
		num = s1->first + s2->first;
		
		vector<string> na;
		na = name[s1->second];
		for(int j=0;j<na.size();j++){
			m[na[j]]++;
		}
		na = name[s2->second];
		for(int j=0;j<na.size();j++){
			m[na[j]]++;
		}
			
		if(s1->second>s2->second){
			s.insert(make_pair(num,s2->second));
			name[s2->second].insert(name[s2->second].end(),name[s1->second].begin(),name[s1->second].end());
		}
		else{
			s.insert(make_pair(num,s1->second));
			name[s1->second].insert(name[s1->second].end(),name[s2->second].begin(),name[s2->second].end());
		}
		
		s.erase(s1);
		s.erase(s2);
	}
	
	for(int i=0;i<n;i++){
		str = v[i];
		count = 0;
		many = 0;
		for(int j=0;j<str.size();j++){
			if(str[j] != ' '){
				word += str[j];
			}
			else{
				count += m[word];
				word = "";
				many++;
			}
		}
		
		
		//cout << count << " " << bit << " " << size << endl;
		cout << fixed << setprecision(7) << double(count)/double(bit*many) << '\n';
		//cout << endl;
	}

}
