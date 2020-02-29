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
	for(int i=0;i<N;i++) dist[i]=1ULL<<60;		//Inserisco dei valori giganti nelle distanze (infinito)
	priority_queue <li, vector<li>, greater<li> > Q; //inizializzazione della priority queue
	dist[start]=0;									//Metto a 0 la distanza del nodo di partenza
	Q.push(make_pair(0,start));						//Faccio cominciare il ciclo inserendo il nodo di partenza
	while(!Q.empty()){
		ull d=Q.top().first;						//tolgo il primo elemento della coda 
		int n=Q.top().second;
		Q.pop();
		for(int i=0;i<G[n].size();i++){									//guardo intorno al nodo e controllo tutti i nodi che posso raggiungere
			if(dist[G[n][i].first]>d+G[n][i].second){				//se il nodo lo posso raggiungere con meno strada di quella che ho gia` fatto
				dist[G[n][i].first]=d+G[n][i].second;				//aggiorno la sua distanza e lo inserisco nella coda come candidato per il
				Q.push(make_pair(dist[G[n][i].first],G[n][i].first));	//percorso piu` breve
			}
		}
    }	
}

 main(){
 	fin>>N>>M>>start>>fine;
 	G.resize(N);
	dist= new ull [N];
	start--;						//interi 1-based (quindi devo abbassarli di 1)
	fine--;
	for(int i=0;i<M;i++){			//caricamento grafo
		int a,b,w;
		fin>>a>>b>>w;
		a--;						//interi 1-based (quindi devo abbassarli di 1)
		b--;
		G[a].push_back(make_pair(b,w));
	}
	
	dijkstra();
	fout<<dist[fine];			//mando fuori la distanza minima del traguardo che mi interessa raggiungere

   return 0;
}
