#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printColourable(vector<int> &colourable){
	cout<<"colourable--->";
	for(int i=0;i<colourable.size();i++)
		cout<<colourable[i]<< " ";
	cout<<"\n";
}
void printAdj(int adj[1000][999]){
	cout<<"adj-->"<<"\n";
	for(int i=0;i<1000;i++){
		for(int j=0;j<999;j++){
			cout<<adj[i][j]<<" ";
		}cout<<"\n";
	}cout<<"\n";
}
void appendChildren(int node, vector<int> &colourable,int adj[1000][999]){
	for(int i=0; i<999; i++){
		if(adj[node][i]==1){
		  colourable.push_back(i);
		}
	}
}

int waysToColour(int node, vector<int> colourable,int adj[1000][999]){
	//cout<<"w2c node "<<node<"\n";
   if(colourable.size()== 0){
   	//base case
   	// cout<<"w2c for node "<<node<<" "<<1<<"\n";
   	return 1;
   }
   else{
   	int temp=0;
   	for(int i=0; i<colourable.size();i++){
   		vector<int> newColourable = colourable;
   		//erase remove for removing current element from colourable, as it has been coloured
   		newColourable.erase(remove(newColourable.begin(),newColourable.end(),colourable[i]),newColourable.end());
   		appendChildren(colourable[i], newColourable, adj);
   		temp+=waysToColour(colourable[i], newColourable,adj);
   	}
   	// cout<<"w2c for node "<<node<<" "<<temp<<"\n";
   	return temp;
   }
}

int main()
{
	int t;
    
    cin >> t;
    for(int i=0; i<t; i++){
    	//for each test
    	//cout<<"Test "<<i+1<<"\n";
    	int adj[1000][999]={0};
    	int n;
    	cin >> n; //number of nodes
    	for(int j=0; j<n-1; j++){
    		int n1,n2;
    		cin >> n1;
    		cin >> n2;
    		//cout<<"edge "<<n1<<" -> "<<n2<<"\n";
    		adj[n1][n2]=1;
    	}
    	//find number of ways to colour
    	vector<int> firstColourable;
    	appendChildren(1,firstColourable,adj);
    //	printColourable(firstColourable);
    //	printAdj(adj);
    	cout<<waysToColour(1,firstColourable,adj)<<"\n";
    }
    return 0;
}
