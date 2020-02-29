#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int ans = 1;
	int N,M;
	fin>>N>>M;
	
	vector<bool> VIS(N, false);
	vector<bool> flyVIS(N, false);
	vector<vector<int> > G;
	G.resize(N);
	
	for(int i=0;i<M;i++){
		int a,b;
		fin>>a>>b;
		G[a].push_back(b);
	}
	
	queue<int> Q;
	Q.push(0);
	VIS[0] = true;
	while(!Q.empty()){
		
		int n = Q.front();
		Q.pop();
		
		for(int i=0;i<G[n].size();i++){
			int flyNode = G[n][i];
			
			if(flyVIS[flyNode])continue;
			else flyVIS[flyNode] = true;
			
			for(int j=0;j<G[flyNode].size();j++){
				
				if(VIS[G[flyNode][j]] )
					continue;
				else{
					ans++;
					VIS[G[flyNode][j]] = true;
					Q.push(G[flyNode][j]);
				}
			}
		}
	} 
	
	fout<<ans;
	return 0;
}
