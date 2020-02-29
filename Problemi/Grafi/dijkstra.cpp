#include <fstream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef pair <int,int> ii;				//definizioni utili di tipi e pair per scirvere meno e piu` veloce
typedef unsigned long long int ull;
typedef pair <ull,int> li;

vector < vector <ii> > G;
ull *dist;
int N,M,start,fine;

void dijkstra(){
	for(int i=0;i<N;i++) dist[i]=1ULL<<60;				//Inserisco dei valori giganti nelle distanze (infinito)
	priority_queue <li, vector<li>, greater<li> > Q; 	//inizializzazione della priority queue
	dist[start]=0;										//Metto a 0 la distanza del nodo di partenza
	Q.push(make_pair(0,start));							//Faccio cominciare il ciclo inserendo il nodo di partenza
	while(!Q.empty())
	{
		ull d=Q.top().first;							//tolgo il primo elemento della coda 
		int n=Q.top().second;
		Q.pop();
		
		//guardo intorno al nodo e controllo tutti i nodi che posso raggiungere
		for(int i=0;i<G[n].size();i++)
		{							
			//se il nodo lo posso raggiungere con meno strada di quella che ho gia` fatto
			if(dist[G[n][i].first]>d+G[n][i].second)
			{
				//aggiorno la sua distanza e lo inserisco nella coda come candidato per il percorso più breve
				dist[G[n][i].first]=d+G[n][i].second;			
				Q.push(make_pair(dist[G[n][i].first],G[n][i].first));	
			}
		}
    }	
}

 main(){
 	fin>>N>>M>>start>>fine;
 	G.resize(N);
	dist= new ull [N];
	start--;						//nel problema i numeri partono da 1 ma io li faccio partire da 0
	fine--;
	 
	 //caricamento grafo
	for(int i=0;i<M;i++)
	{			
		int a,b,w;
		fin>>a>>b>>w;
		a--;						//nel problema i numeri partono da 1 ma io li faccio partire da 0
		b--;
		G[a].push_back(make_pair(b,w));
	}
	
	dijkstra();
	fout<<dist[fine];			//mando fuori la distanza minima del traguardo che mi interessa raggiungere

   return 0;
}
