#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
	
	int N,M;
	fin>>N>>M;
	bool vis[N];
	vector<vector<int> > g;
	g.resize(N);
	
	int c=0;
	
	for(int i=0;i<N;i++)	
		vis[i] = false;
		
	for(int i=0;i<M;i++)
	{
		int a,b;
		fin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	queue<int> q;	
	for(int j=0;j<N;j++)
	{
		if(vis[j]==true)
			continue;
		q.push(j);
		//bfs
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			if(vis[x]==true)
				continue;
			vis[x]=true;
			for(int i=0;i<g[x].size();i++)
			{
				if(vis[g[x][i]]==true)
					continue;
				//vis[g[x][i]]=true;
				q.push((g[x][i]));
			}
		}
		c++;
	}
	fout<<c-1;
	return 0;
}
