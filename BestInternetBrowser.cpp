#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //read input
    int tc;
    int dc;
    char dot ='.';

    string website;
    int nv;
    int vowels[69]={0};

    cin >> tc;
    cin.ignore();

    for(int i=1;i<=tc;i++){
    	getline(cin,website);
    	nv = 0;
    	dc = 0;
    	for(int j=0;j<=website.length()-1;j++){
    		if(website[j] == 'a' || website[j]=='e' || website[j]=='i' || website[j]=='o' || website[j]=='u' ){
    			nv++;
    		}
    		if(website[j]== dot){
    			dc++;
    			if(dc == 2){
    			break;
    			}
    		}
    	}
    	cout <<(website.length() - (nv+4))<<"/"<<website.length()<<"\n";
    }
    return 0;
}
