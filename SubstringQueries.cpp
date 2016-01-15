#include <iostream>
#include <string>
#include <map>
using namespace std;



bool match(string base,string sub){
	int flag = false;
	map<char,int> base_map;
	if(sub.length()>base.length()){
		return false;
	}
	else{
		for(int i=0; i<base.length(); i++){
			base_map[base[i]]++;
		}
		for(int j=0; j<sub.length(); j++){
			if(base_map[sub[j]]<1){
			    flag = true;
			}
		}
	}
	if(flag == true){ //match_failed = true
		return false;
	}
	else{
		//cout<<"base_map[a]="<<base_map['a']<< " base_map[b]="<<cout<<base_map['b']<<"\n";
		return true;
	}
}
int main()
{
    int t; //number of test cases(main loop)
    string s;
    int nq;
    string query;
    cin >> t;
    for(int i=0;i<t;i++){
    	cin >> s;
    	cin >> nq;

    	for(int j=0; j<nq; j++){
    		cin >> query;
    		int count=0;
    		int start =0;
    		int end =0;
    		while(start<s.length()){
	    		string base = s.substr(start,(end-start+1));
	    		//callmatch and update count
	    		bool ma = match(base,query);
	    		if(ma ==1){
	    			count++;
	    		}
	    		// check and update start and end
	    		end++;
	    		if(end>=s.length()){
	    			start++;
	    			end = start;
	    		}	
    		}
    		cout<<count<<"\n";
    	}
    }
    return 0;
}
