#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
	
	int ans=0;
	
	//numero nodi, numero archi
	int N,M;
	fin>>N>>M;
	
	//creo un grafo con N nodi
	vector<vector<int> > g;
	g.resize(N);
	
	//array per segnarmi quali nodi ho visitato
	bool vis[N];
	for(int i=0;i<N;i++)	
		vis[i] = false;
	
	//creo il grafo definendo i collegamenti tra nodi
	for(int i=0;i<M;i++)
	{
		int a,b;
		fin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	//sfruttando una queue, faccio partire una BFS (visita in larghezza) da ogni nodo che non è ancora stato visitato
	queue<int> q;	
	for(int j=0;j<N;j++)
	{
		//seleziono il possibile nodo da cui far partire una nuova BFS, 
		//se è già stato visitato passo alla prossima iterazione del ciclo for
		//sennò inserisco il nodo j-esimo nella coda
		if(vis[j]==true)
			continue;
		q.push(j);
		
		//BFS
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			//se il nodo in cui mi trovo (x) è già stato visitato, passo alla prossima iterazione del ciclo while
			//in caso contrario comunque segno vis[x] = true
			if(vis[x]==true)
				continue;
			vis[x]=true;
			
			//per ogni nodo collegato a quello attuale
			for(int i=0;i<g[x].size();i++)
			{
				//lo inserisco come possibile nodo da visitare solo se non è ancora stato visitato
				if(vis[g[x][i]]==true)
					continue;
				q.push((g[x][i]));
			}
		}
		
		//la risposta al problema aumenta di 1 perchè ho visitato un intero nuovo grafo sconnesso dagli altri
		ans++;
	}
	
	fout<<ans-1;
	return 0;
}
