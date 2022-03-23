#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	string com,a,str;
	vector<pair<string,int> > v;
	map<string,int> m1;
	map<string,int> m2;
	map<string,int>::iterator it;
	
	int mul,len,n,vec=0;
	
	cin >> com;
	
	for(int i=0;i<com.length();i++){
		
		if(com[i]=='('){
			vec++;
			continue;
		}
		else if(com[i]==')'){
			vec--;
			mul = 0;
			do{
				mul *= 10;
				mul += int(com[i+1])-'0';
				i++;
			}while(int(com[i+1])-'0'>=0 && int(com[i+1])-'0'<=9);
			
			for(int j=0;j<v.size();j++){
				v[j].second *= mul;
			}
			
			if(!vec){
				for(int j=0;j<v.size();j++){
					a = v[j].first;
					len = a.length();
					if(len==1){
						it = m1.find(a);
						if(it!=m1.end()){
							it->second += v[j].second;	
						}
						else{
							m1.insert(make_pair(a,v[j].second));
						}
					}
					else if(len==2){
						it = m2.find(a);
						if(it!=m2.end()){
							it->second += v[j].second;	
						}
						else{
							m2.insert(make_pair(a,v[j].second));
						}
					}	
				
				}
				v.clear();
			}	
			continue;
		}
		
		
		if(vec){ 
			str += com[i];
			if(int(com[i+1])>=97 && int(com[i+1])<=122){
				str += com[++i];
				
				if(int(com[i+1])-'0'>=0 && int(com[i+1])-'0'<=9){
					n = 0;
					do{
						n *= 10;
						n += int(com[i+1])-'0';
						i++;
					}while(int(com[i+1])-'0'>=0 && int(com[i+1])-'0'<=9);
					
				}
				else{
					n = 1;
				}
				v.push_back(make_pair(str,n));
			
			}
			else{
				if(int(com[i+1])-'0'>=0 && int(com[i+1])-'0'<=9){
					n = 0;
					do{
						n *= 10;
						n += int(com[i+1])-'0';
						i++;
					}while(int(com[i+1]-'0')>=0 && int(com[i+1])-'0'<=9);
					
				}
				else{
					n = 1;
				}
				
				v.push_back(make_pair(str,n));
			}
			
			str = "";
		}
		else{
			str += com[i];
			if(int(com[i+1])>=97 && int(com[i+1])<=122){
				str += com[++i];
				
				if(int(com[i+1])-'0'>=0 && int(com[i+1])-'0'<=9){
					n = 0;
					do{
						n *= 10;
						n += int(com[i+1])-'0';
						i++;
					}while(int(com[i+1])-'0'>=0 && int(com[i+1])-'0'<=9);
				}
				else{
					n = 1;
				}
				
				it = m2.find(str);
				if(it!=m2.end()){
					it->second += n;
				}
				else{
					m2.insert(make_pair(str,n));	
				}
				
			}
			else{
				if(int(com[i+1])-'0'>=0 && int(com[i+1])-'0'<=9){
					n = 0;
					do{
						n *= 10;
						n += int(com[i+1])-'0';
						i++;
					}while(int(com[i+1])-'0'>=0 && int(com[i+1])-'0'<=9);
				}
				else{
					n = 1;
				}
				
				it = m1.find(str);
				if(it!=m1.end()){
					it->second += n;	
				}
				else{
					m1.insert(make_pair(str,n));
				}
			}
			str = "";
		}
		
	}
	
	cout << m1.size() << '\n';
	for(it=m1.begin();it!=m1.end();it++){
		cout << it->first << ":" << it->second << '\n';
	}
	
	cout << m2.size() << '\n';
	for(it=m2.begin();it!=m2.end();it++){
		cout << it->first << ":" << it->second << '\n';	
	}
	
	return 0;
}
